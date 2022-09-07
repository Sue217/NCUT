`timescale 1ns / 1ps

module grey(
  input [7:0] bit,
  output [7:0] grey
);

  assign grey = (bit >> 1) ^ bit;

endmodule
