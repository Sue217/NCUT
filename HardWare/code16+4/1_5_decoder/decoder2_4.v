`timescale 1ns / 1ps

module decoder2_4(en, a, b, y);

  input en, a, b;
  output [3:0] y;

  wire n_en, n_a, n_b;
  not g0(n_en, en);
  not g1(n_a, a);
  not g2(n_b, b);

  assign y[0] = ~(n_en & n_a & n_b);
  assign y[1] = ~(n_en & n_a & b);
  assign y[2] = ~(n_en & a & n_b);
  assign y[3] = ~(n_en & a & b);

endmodule
