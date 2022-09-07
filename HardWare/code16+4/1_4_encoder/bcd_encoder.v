`timescale 1ns / 1ps

module bcd_encoder(en, cin, cout);

input en;
input [9:0] cin;
output reg [3:0] cout;

always @(cin, en)
  begin
    if (en == 0)
      cout = 4'bXXX;
     else
      case(cin)
        10'b0000000001: cout = 4'b0000;    // 0
        10'b0000000010: cout = 4'b0001;    // 1
        10'b0000000100: cout = 4'b0010;    // 2
        10'b0000001000: cout = 4'b0011;    // 3
        10'b0000010000: cout = 4'b0100;    // 4
        10'b0000100000: cout = 4'b0101;    // 5
        10'b0001000000: cout = 4'b0110;    // 6
        10'b0010000000: cout = 4'b0111;    // 7
        10'b0100000000: cout = 4'b1000;    // 8
        10'b1000000000: cout = 4'b1001;    // 9
        default: cout = 4'bX;
      endcase
    end
endmodule
