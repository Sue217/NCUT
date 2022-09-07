`timescale 1ns / 1ps

module bit_comparator_tb;

  reg a;
  reg b;

  wire greater;
  wire less;
  wire equal;
  reg [1:0] counter;

  bit_comparator comparator(
    .a(a),
    .b(b),
    .greater(greater),
    .less(less),
    .equal(equal)
  );

  initial
  begin
    a = 0;
    b = 0;
    counter = 0;
  end

  always @(a or b) begin

    for (counter = 0; counter < 4; counter = counter + 1)
      #100 {a, b} = counter;
      #100 $stop;
    end
endmodule
