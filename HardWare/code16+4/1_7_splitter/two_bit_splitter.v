`timescale 1ns / 1ps

module two_bit_splitter (
  input s,
  input d,
  output y0,
  output y1
);

  not(n_s, s);          // n_s = ~s;
  and(y0, n_s, d);      // y0 = n_s & d;
  and(y1, s, d);        // y1 = s & d;

endmodule