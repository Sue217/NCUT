`timescale 1ns / 1ps

module MUX2_1_tb;
  wire out;
  reg d0, d1, s;
  MUX2_1 mux (.Y(out), .D0(d0), .D1(d1), .S(s));
  
  initial
  begin
    d0 = 1'b0;
    d1 = 1'b0;
    s = 1'b0;
    #100;
  end
  
  always #40 d0 = ~d0;
  always #20 d1 = ~d1;
  always #10 s = ~s;

endmodule