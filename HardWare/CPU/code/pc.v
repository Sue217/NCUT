/*
    file: pc.v
    author: Jingbo Su
    created: August 2022
*/

module PC (
  output reg[31:0] next,
  input wire[31:0] current,
  input wire clk,
  input wire rst
);

always @(posedge clk or negedge rst) begin
  if (!rst) next = 0;
  else if (clk) next = current;
end

endmodule

// NEXT module: what pc will be next step
module NEXT (
  output reg[31:0] next,
  input wire[31:0] pc,
  input wire[15:0] imm_i_16,  // op: 6-bit, imm: 16-bit, I-type instruction (immediate)
  input wire[25:0] imm_r_26,  // op: 6-bit, imm: 26-bit, J-type instruction (address)
  input wire[31:0] rs,        // register rs
  input wire[1:0] next_op
);

wire[31:0] ex_imm16, ex_imm26;

Extend #(.in_width(16)) Extend_0 (
  // parameterization of modules allows for module reuse powerfully!
  .in(imm_i_16),
  .sign_ext(imm_i_16[15]),
  .result(ex_imm16)
);
Extend #(.in_width(26)) Extend_1 (
  .in(imm_r_26),
  .sign_ext(imm_r_26[25]),
  .result(ex_imm26)
);

always @(pc or imm_i_16 or imm_r_26 or rs or next_op) begin
  case (next_op)
    2'b00: next = pc + 4; // seq-instructions
    2'b01: next = pc + 4 + (ex_imm16 << 2); // beq & bne
    2'b10: next = ex_imm26 << 2;  // j & jal
    2'b11: next = rs; // jr
    default: ;
  endcase
end

endmodule