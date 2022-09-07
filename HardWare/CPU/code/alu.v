/*
    file: alu.v
    author: Jingbo Su
    created: August 2022
*/

module ALU(
  output reg[31:0] alu_result,
  output wire eq,
  input wire[31:0] a,
  input wire[31:0] b,
  input wire[3:0] alu_op
);

reg[32:0] val;

always @(a or b or alu_op) begin
  case (alu_op)
    4'b0000: alu_result = a + b;    // add
    4'b0001: alu_result = a - b;    // sub
    4'b0010: alu_result = a & b;    // and
    4'b0011: alu_result = a | b;    // or
    4'b0100: alu_result = a ^ b;    // xor
    4'b0101: alu_result = !(a | b); // nor
    4'b0110: begin                          // slt: select less
      val = {a[31], a} - {b[31], b};// {ex-sign, 32-bit val}
      alu_result = 32'd0 | val[32];
    end
    4'b0111: alu_result = b << a;   // sll, sllv
    4'b1000: alu_result = b >> a;   // srl, srlv
    4'b1001: alu_result = b >>> a;  // sal, srav
    4'b1010: alu_result = b << 16;  // lui
    4'b1111:;
  endcase
end

assign eq = (a == b ? 1 : 0);

endmodule