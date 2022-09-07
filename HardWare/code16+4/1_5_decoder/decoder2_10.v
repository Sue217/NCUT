`timescale 1ns / 1ps

module decoder2_10 (
  input [3:0] addr,
  output [15:0] dec
);

  assign dec[0] = ~addr[0] & ~addr[1] & ~addr[2] & ~addr[3];
  assign dec[1] = ~addr[0] & ~addr[1] & ~addr[2] & addr[3];
  assign dec[2] = ~addr[0] & ~addr[1] & addr[2] & ~addr[3];
  assign dec[3] = ~addr[0] & ~addr[1] & addr[2] & addr[3];
  assign dec[4] = ~addr[0] & addr[1] & ~addr[2] & ~addr[3];
  assign dec[5] = ~addr[0] & addr[1] & ~addr[2] & addr[3];
  assign dec[6] = ~addr[0] & addr[1] & addr[2] & ~addr[3];
  assign dec[7] = ~addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[8] = addr[0] & ~addr[1] & ~addr[2] & ~addr[3];
  assign dec[9] = addr[0] & ~addr[1] & ~addr[2] & addr[3];
  assign dec[10] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[11] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[12] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[13] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[14] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[15] = addr[0] & addr[1] & addr[2] & addr[3];
endmodule