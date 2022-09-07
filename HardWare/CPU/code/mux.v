/*
    file: mux.v
    author: Jingbo Su
    created: August 2022
*/

module MUX #(parameter in_width = 32
) (
  // parameterization of modules allows for module reuse powerfully!
  output reg[in_width-1:0] out,
  input wire[in_width-1:0] in0,
  input wire[in_width-1:0] in1,
  input wire sel
);

always @(in0 or in1 or sel) begin
  // if sel == 1, select in1, otherwise select in0
  if (sel) out = in1;
  else out = in0;
end

endmodule