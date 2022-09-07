`timescale 1ns / 1ps

module splitter2_4(in, out, sel);

  input in;
  input [1:0] sel;
  output [3:0] out;
  
  wire [3:0] dd;
  
  two_bit_splitter_0 u0 (
    .d(in),
    .s(sel[0]),
    .y0(dd[0]),
    .y1(dd[1])
  );
  
  two_bit_splitter_0 u1 (
    .d(in),
    .s(sel[1]),
    .y0(dd[2]),
    .y1(dd[3])
  );
  
  assign out = dd;
endmodule
