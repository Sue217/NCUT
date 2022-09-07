`timescale 1ns / 1ps

module encoder4_2(
  input d0, d1, d2, d3,
  output a0, a1
);
  wire x, y, z;
  not g1(x, d2);        // x = ~d2
  and g2(y, x, d1);     // y = x & d1
  or g3(a0, y, d3);     // a0 = y | d3
  or g4(a1, d2, d3);    // a1 = d2 | d3
endmodule
