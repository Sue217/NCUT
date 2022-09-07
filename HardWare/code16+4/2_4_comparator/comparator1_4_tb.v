`timescale 1ns / 1ps

module comparator1_4_tb;

  reg [4:0] a, b;
  wire greater, equal, less;
  
  initial
  begin
    {a, b} = 8'd0;
    #(16 * 16) $finish;
  end
  
  always
  begin
    #10
    {a, b} = {a, b} + 1;
  end
  
  comparator1_4 comparator(
    .a(a),
    .b(b),
    .greater(greater),
    .equal(equal),
    .less(less)
  );
endmodule
