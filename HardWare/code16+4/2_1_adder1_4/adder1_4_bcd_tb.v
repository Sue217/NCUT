`timescale 1ns / 1ps

module adder1_4_bcd_tb;

  reg [3:0] a, b;
  reg cin;
  wire [3:0] s;
  wire cout;
  
  adder1_4_bcd_wrapper adder(
    .a_0(a[0]),
    .a_1(a[1]),
    .a_2(a[2]),
    .a_3(a[3]),
    .b_0(b[0]),
    .b_1(b[1]),
    .b_2(b[2]),
    .b_3(b[3]),
    .cin_0(cin),
    .sum_0(s[0]),
    .sum_1(s[1]),
    .sum_2(s[2]),
    .sum_3(s[3]),
    .cout_0(cout)
  );
  
  initial
  begin
    a = 0;  b = 0;  cin = 0;   #100;
    a = 6;  b = 9;  cin = 0;   #100;
    a = 3;  b = 3;  cin = 1;   #100;
    a = 4;  b = 5;  cin = 0;   #100;
    a = 8;  b = 2;  cin = 0;   #100;
    a = 9;  b = 9;  cin = 1;   #100;
    a = 8;  b = 1;  cin = 0;   #100;
    a = 6;  b = 2;  cin = 0;   #100;
    a = 9;  b = 1;  cin = 1;   #100;
    a = 7;  b = 0;  cin = 0;   #100;
  end
endmodule
