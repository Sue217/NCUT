`timescale 1ns / 1ps

module project_16_tb;
  reg a;
  reg b;
  reg cin;

  wire sum;
  wire cout;

  bcd_adder adder(
    .a(a), 
    .b(b), 
    .cin(cin), 
    .sum(sum), 
    .cout(cout)
  );

  initial
  begin
    a = 0;  b = 0;  cin = 0;   #100;
    a = 6;  b = 9;  cin = 0;   #100;
    a = 3;  b = 3;  cin = 1;   #100;
    a = 4;  b = 5;  cin = 0;   #100;
    a = 8;  b = 2;  cin = 0;   #100;
    a = 9;  b = 9;  cin = 1;   #100;
  end    
endmodule