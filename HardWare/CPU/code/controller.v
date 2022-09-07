/*
    file: controller.v
    author: Jingbo Su
    created: August 2022
*/

module Controller (
  output reg control_a,   // control_a: 0: reg_1, 1: shamt shift
  output reg control_b,   // control_b: 0: reg_2, 1: immediate extend
  output reg mem_write,   // enable write to memory
  output reg reg_write,   // enable write to register
  output reg mem_to_data, // pass data as memory to Data Memory
  output reg sign_ext,    // extend sign or not
  output reg dest,    // destination register, 1: rd 0: rt
  output reg jal,
  output reg[3:0] alu_op,
  output reg[1:0] next_op,

  input wire[5:0] op,
  input wire[5:0] func,
  input wire eq
);

always @(op or func or eq) begin
  // R type instruction (op = [000000])
  if (op == 6'b000000) begin
    // ALU
    if (func[5]) begin
      control_a <= 0;   // from reg_1
      control_b <= 0;   // from reg_2
      mem_write <= 0;   // no need to write to memory
      reg_write <= 1;   // write into reg
      mem_to_data <= 0; // don't access memory
      sign_ext <= 0;    // don't extend sign
      dest <= 1;        // to rd
      jal <= 0;
      next_op <= 2'b00;

      case (func[3:0])
        4'b0000: alu_op <= 4'b0000;   // add
        4'b0001: alu_op <= 4'b0000;   // addu
        4'b0010: alu_op <= 4'b0001;   // sub
        4'b0011: alu_op <= 4'b0001;   // subu
        4'b0100: alu_op <= 4'b0010;   // and
        4'b0101: alu_op <= 4'b0011;   // or
        4'b0110: alu_op <= 4'b0100;   // xor
        4'b0111: alu_op <= 4'b0101;   // nor
        4'b1010: alu_op <= 4'b0110;   // slt
        4'b1011: alu_op <= 4'b0110;   // sltu
        default: alu_op <= 4'b1111;
      endcase
    end
    else begin
      // jr instructions  [001000]
      if (func[3]) begin
        control_a <= 0;
        control_b <= 0;
        mem_write <= 0;
        reg_write <= 0; // do not write data
        mem_to_data <= 0;
        sign_ext <= 0;
        dest <= 0;  // rd
        jal <= 0;
        next_op <= 2'b11; // jump
        alu_op <= 4'b1111;  // do nothing
      end
      // shift instructions
      else if (func[5:3] == 3'b000) begin
        if (func[2])  control_a <= 1; // incorporate shamt
        else  control_a <= 0; // without shamt

        control_b <= 0;
        mem_write <= 0;
        reg_write <= 1;   // write into reg
        mem_to_data <= 0;
        sign_ext <= 0;
        dest <= 1;  // rd
        jal <= 0;
        next_op <= 2'b00;

        case (func[1:0])
          2'b00: alu_op <= 4'b0111; // sll & sllv
          2'b10: alu_op <= 4'b1000; // srl & srlv
          2'b11: alu_op <= 4'b1001; // sra & srav
        endcase
      end
    end
  end
  // J type instructions
  else if (op[5:1] == 5'b00001) begin
    // jal instruction [000011]
    if (op[0]) begin
      control_a <= 0;
      control_b <= 0;
      mem_write <= 0;
      reg_write <= 1; // write into rs
      mem_to_data <= 0;
      sign_ext <= 0;
      dest <= 0;  // rt
      jal <= 1;
      next_op <= 2'b10; // j & jal
      alu_op <= 4'b1111;  // do nothing
    end
    // j instruction [000010]
    else begin

      control_a <= 0;
      control_b <= 0;
      mem_write <= 0;
      reg_write <= 0;
      mem_to_data <= 0;
      sign_ext <= 0;
      dest <= 0;  // rd
      jal <= 0;
      next_op <= 2'b10; // j & jal
      alu_op <= 4'b1111;  // do nothing
    end
  end
  // I type instructions
  else begin
    if (op[5:3] == 3'b001) begin

      control_a <= 0;
      control_b <= 1; // $ext_imm instead of reg_2
      mem_write <= 0;
      reg_write <= 1; // write into reg
      mem_to_data <= 0;
      dest <= 0;  // rd
      jal <= 0;
      next_op <= 2'b00;
      
      case (op[2:0])
        // addi
        3'b000: begin
          alu_op <= 4'b0000;
          sign_ext <= 1;
        end
        // addiu
        3'b001: begin
          alu_op <= 4'b0000;
          sign_ext <= 1;
        end
        // andi
        3'b100: begin
          alu_op <= 4'b0010;
          sign_ext <= 0;
        end
        // ori
        3'b101: begin
          alu_op <= 4'b0011;
          sign_ext <= 0;
        end
        // xori
        3'b110: begin
          alu_op <= 4'b0100;
          sign_ext <= 0;
        end
        // lui
        3'b111: begin
          alu_op <= 4'b1010;
          sign_ext <= 0;
        end
        // slti
        3'b010: begin
          alu_op <= 4'b0110;
          sign_ext <= 1;
        end
        // sltiu
        3'b011: begin
          alu_op <= 4'b0110;
          sign_ext <= 0;
        end
      endcase
    end
    // load & store instruction
    else if (op[5:4] == 2'b10 && op[2:0] == 3'b011) begin
      control_a <= 0;
      control_b <= 1; // $imm instead of rd
      mem_write <= 0;
      sign_ext <= 1;
      dest <= 0;  // rd
      jal <= 0;
      next_op <= 2'b00; // j & jal
      alu_op <= 4'b0000;  // do nothing

      // sw: fetch data from reg and write into memory
      if (op[3]) begin
        mem_write <= 1;
        reg_write <= 0;
      end
      // lw: fetch data from memory and write into reg
      else begin
        mem_write <= 0;
        reg_write <= 1;
      end
    end
    // condition branch instructions
    else if (op[5:1] == 5'b00010) begin
      control_a <= 0;
      control_b <= 0;
      mem_write <= 0;
      reg_write <= 0;
      mem_to_data <= 0;
      sign_ext <= 0;
      dest <= 0;
      jal <= 0;
      alu_op <= 4'b0001;

      // bne: if rt != rs, then (PC)<-(PC) + 4 + (sign-extend-offset << 2)
      if (op[0]) begin
        if (eq) next_op <= 2'b00;
        else next_op <= 2'b01;  // not equal
      end
      // beq: if rt == rs, then (PC)<-(PC) + 4 + (sign-extend-offset << 2)
      else begin
        if (eq) next_op <= 2'b01; // equal
        else next_op <= 2'b00;
      end
    end
  end
end

endmodule