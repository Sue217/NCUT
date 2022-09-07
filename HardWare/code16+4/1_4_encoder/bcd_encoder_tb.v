`timescale 1ns / 1ps

module bcd_encoder_tb;

  reg en;
  reg [9:0] cin;
  wire [3:0] cout;
  
  bcd_encoder encoder(en, cin, cout);
  
  initial
  begin
    en = 1; cin = 10'b0000000001; #50
    en = 1; cin = 10'b0000000010; #50
    en = 1; cin = 10'b0000000100; #50
    en = 1; cin = 10'b0000001000; #50
    en = 1; cin = 10'b0000010000; #50
    en = 1; cin = 10'b0000100000; #50
    en = 1; cin = 10'b0001000000; #50
    en = 1; cin = 10'b0010000000; #50
    en = 1; cin = 10'b0100000000; #50
    en = 1; cin = 10'b1000000000; #50
    $finish;
  end
endmodule
