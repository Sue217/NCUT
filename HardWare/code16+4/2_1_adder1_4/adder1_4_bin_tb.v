`timescale 1ns / 1ps

module adder1_4_bin_tb;

  reg [3:0] a, b;
  reg c;
  wire [3:0] s;
  wire co;
  
  adder1_4_bin_wrapper adder(
    .a_0(a[0]),
    .a_1(a[1]),
    .a_2(a[2]),
    .a_3(a[3]),
    .b_0(b[0]),
    .b_1(b[1]),
    .b_2(b[2]),
    .b_3(b[3]),
    .c_0(c),
    .sum_0(s[0]),
    .sum_1(s[1]),
    .sum_2(s[2]),
    .sum_3(s[3]),
    .carry_0(co)
  );
  
  initial
  begin
    {a, b, c} = 9'b0;
    #1000 $finish;
  end
  
  always
  begin
    #10
    {a, b, c} = {a, b, c} + 1'b1;
  end
endmodule
