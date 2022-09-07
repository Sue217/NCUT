/*
    file: cpu.v
    author: Jingbo Su
    created: August 2022
*/

module CPU (
  input wire clk,
  input wire rst,
  output wire[2:0] sel,
  output wire[7:0] seg
);

wire[31:0] pc, next;
wire[31:0] instruction;
wire[31:0] reg_result, mem_result;

wire control_a, control_b;
wire mem_write, reg_write;
wire mem_to_data;
wire sign_ext;
wire dest;
wire jal;
wire[3:0] alu_op;
wire[1:0] next_op;

wire[4:0] reg_1_sel, reg_2_sel, w_sel;
wire[31:0] data, reg_1, reg_2;
wire[4:0] final;  // select destination is rt or rd

wire[31:0] shamt, ex_imm;

wire[31:0] A, B, alu_result;
wire eq;

wire[31:0] read, write;

// fetch instructions
PC fetch (
  .next(pc),
  .current(next), // next = pc + 4 first, if seq won't jump
  .clk(clk),
  .rst(rst)
);

// calculate next instruction (seq or jmp)
NEXT jump (
  .pc(pc),
  .next(next),
  .imm_i_16(instruction[15:0]), // beq & bne
  .imm_r_26(instruction[25:0]), // j & jal
  .rs(reg_1),
  .next_op(next_op)
);

// controller
Controller control (
  // pins and wires have the same name can be writen implicitly in .name connections
  // why it does not work???
  .control_a(control_a),
  .control_b(control_b),
  .mem_write(mem_write),
  .reg_write(reg_write),
  .mem_to_data(mem_to_data),
  .sign_ext(sign_ext),
  .dest(dest),
  .jal(jal),
  .alu_op(alu_op),
  .next_op(next_op),
  .op(instruction[31:26]),
  .func(instruction[5:0]),
  .eq(eq)
);

assign reg_1_sel = instruction[25:21];  // rs
assign reg_2_sel = instruction[20:16];  // rt

wire[31:0] res;

// registers
Regs regs (
  .reg_1(reg_1),
  .reg_2(reg_2),
  .res(res),
  .reg_1_sel(reg_1_sel),
  .reg_2_sel(reg_2_sel),
  .en(reg_write),
  .write_sel(w_sel),
  .write_data(data),
  .clk(clk)
);

wire[11:0] val;
assign val = res[11:0];

// execution process
// all pins and wires have the same name
// this is the most powerful form of implicit association
// its best reserved for use at the top level testbench/top module
// why ALU alu_0(.*) does not work???

ALU alu (
  .a(A),
  .b(B),
  .alu_op(alu_op),
  .eq(eq),
  .alu_result(alu_result)
);

// access instruction memory
Instructon_Memory insm (
  .pos(pc),
  .read(instruction)
);

// access data memory
Data_Memory datam (
  .pos(alu_result),
  .write(reg_2),
  .ret(read),
  .en(mem_write),
  .clk(clk)
);

// in the module declaration, the keyword `parameter` is not required
// it does read more clearly however!
MUX #(.in_width(5)) MUX_0 (
  // select dest_reg: rt or rd
  .out(final),
  .in0(instruction[20:16]),
  .in1(instruction[15:11]),
  .sel(dest)
);

MUX #(.in_width(5)) MUX_1 (
  // select jr: goto $31 or not
  .out(w_sel),
  .in0(final),
  .in1(31),
  .sel(jal)
);

MUX #(.in_width(32)) MUX_2 (
  // select where to write data: next or write back
  .out(data),
  .in0(write),
  .in1(next),
  .sel(jal)
);

MUX #(.in_width(32)) MUX_3 (
  // select ordinary or (shamt) shift operation
  .out(A),
  .in0(reg_1),
  .in1(shamt),
  .sel(control_a)
);

MUX #(.in_width(32)) MUX_4 (
  // select ordinary or (I-type / J-type) needs extend immediate operation
  .out(B),
  .in0(reg_2),
  .in1(ex_imm),
  .sel(control_b)
);

MUX #(.in_width(32)) MUX_5 (
  // select write data of the reg or address in memory as the data of the reg...
  .out(write),
  .in0(alu_result),
  .in1(read),
  .sel(mem_to_data)
);

// handling $imm in instructions
// in the module declaration, the keyword `parameter` is not required
// it does read more clearly however!
Extend #(.in_width(5)) Extend_0 (
  // shamt(shift amount) extend: 5-bit->32-bit
  // sll & srl & sra
  .result(shamt),
  .in(instruction[10:6]),
  .sign_ext(0)  // no sign extend
);

Extend #(.in_width(16)) Extend_1 (
  // immediate extend: 16-bit->32-bit
  .result(ex_imm),
  .in(instruction[15:0]),
  .sign_ext(sign_ext)   // sign extend
);

SEG seven_seg (
  .clk(clk),
  .val(val),
  .sel(sel),
  .seg(seg)
);

// check halt intruction
always @(*) begin
  if(instruction == 32'hffffffff) begin
    $finish;
  end
end

endmodule