`timescale 1ns / 1ps

module binary_adder (
  input a,
  input b,
  input c,
  output sum,
  output carry
);
  assign sum = a ^ b ^ c;
  assign carry = (a & b) | (a & c) | (b & c);
endmodule