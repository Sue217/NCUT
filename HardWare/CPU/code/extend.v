/*
    file: extend.v
    author: Jingbo Su
    created: August 2022
*/

module Extend #(
  parameter in_width = 16,
  parameter out_width = 32
) (
  // parameterization of modules allows for module reuse powerfully!

  // zero/sign extend from 16-bit to 32-bit
  output wire[out_width-1:0] result,
  input wire[in_width-1:0] in,
  input wire sign_ext
);

reg [out_width-in_width-1:0] ext_bit; // extend bits

always @(in or sign_ext) begin
  // use if...else instead of an MUX
  if (sign_ext) begin
    // sign extend
    if (in[in_width - 1]) ext_bit = 32'd0 - 1; // negitive
    else ext_bit = 0; // positive
  end
  else ext_bit = 0; // zero extend
end

assign result = {ext_bit, in};

endmodule