`timescale 1ns / 1ps

module encoder4_2_tb;
  reg d0, d1, d2, d3;
  wire a0, a1;

  encoder4_2 encoder (
    .d0(d0),
    .d1(d1),
    .d2(d2),
    .d3(d3),
    .a0(a0),
    .a1(a1)
  );
  
  initial
  begin
    
    d0 = 1; d1 = 0; d2 = 0; d3 = 0;
    #100; d0 = 0; d1 = 1; d2 = 0; d3 = 0;
    #100; d0 = 0; d1 = 0; d2 = 1; d3 = 0;
    #100; d0 = 0; d1 = 0; d2 = 0; d3 = 1;
  end
endmodule