`timescale 1ns / 1ps

module priority_encoder (
  input [3:0] D,
  output [1:0] ENC,
  output VLD
);

  assign ENC[0] = (~D[2] & D[1]) | D[3];
  assign ENC[1] = D[2] | D[3];
  assign VLD = D[0] | D[1] | D[2] | D[3];
endmodule