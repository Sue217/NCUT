`timescale 1ns / 1ps

module project_16_tb;
  reg s, d;
  wire y0, y1;
  
  two_bit_splitter splitter(
    .s(s),
    .d(d),
    .y0(y0),
    .y1(y1)
  );
  
  initial
  begin
    s = 0; d = 0; #100
    s = 0; d = 1; #100
    s = 1; d = 0; #100
    s = 1; d = 1; #100
    $finish;
  end
endmodule