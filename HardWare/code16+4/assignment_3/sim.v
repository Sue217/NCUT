`timescale 1ns / 1ps

module sim_tb;

reg [1:0] a, b;
reg c;

wire [1:0] s;
wire co;

design_1_wrapper adder(
  .a_0(a[0]),
  .a_1(a[1]),
  .b_0(b[0]),
  .b_1(b[1]),
  .c_0(c),
  .sum_0(s[0]),
  .sum_1(s[1]),
  .carry_0(co)
);

  initial
  begin
    {a, b, c} = 5'b0;
    #1000 $finish;
  end

  always
  begin
    #10
    {a, b, c} = {a, b, c} + 1'b1;
  end

endmodule