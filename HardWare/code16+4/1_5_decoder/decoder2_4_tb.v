`timescale 1ns / 1ps

module decoder2_4_tb;

  reg a, b, en;
  wire [3:0] y;
  decoder2_4 decoder(en, a, b, y);
  
  initial
  begin
    en = 1; a = 1'b0; b = 1'b0; #50
    en = 0; a = 0; b = 0; #50
    en = 0; a = 0; b = 1; #50
    en = 0; a = 1; b = 0; #50
    en = 0; a = 1; b = 1; #50
    $finish;
  end
endmodule
