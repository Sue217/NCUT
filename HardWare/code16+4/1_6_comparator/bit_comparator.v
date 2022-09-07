`timescale 1ns / 1ps

module bit_comparator(
  input a,
  input b,
  output greater,
  output less,
  output equal
);

  assign greater = (a & 1) & (~(b | 0));
  assign less = (~(a | 0)) & (b & 1);
  assign equal = a ^ (~b);
endmodule
