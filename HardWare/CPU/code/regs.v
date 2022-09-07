/*
    file: regs.v
    author: Jingbo Su
    created: August 2022
*/

module Regs(
  output wire[31:0] reg_1,
  output wire[31:0] reg_2,
  output wire[31:0] res,
  input wire[4:0] reg_1_sel,
  input wire[4:0] reg_2_sel,
  input wire en,
  input wire[4:0] write_sel,
  input wire[31:0] write_data,
  input wire clk
);

reg[31:0] regs[0:31]; // 32 register group

assign reg_1 = regs[reg_1_sel];
assign reg_2 = regs[reg_2_sel];
assign res = regs[3];

integer i;
initial begin
  for(i = 0; i < 32; i = i + 1) begin
    regs[i] = i;
  end
end

always @(negedge clk) begin
  // write data into registers
  if (en) regs[write_sel] <= write_data;
end

endmodule