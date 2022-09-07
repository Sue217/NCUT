`timescale 1ns / 1ps

module binary_adder_tb;
  reg a, b, c;
  wire sum, carry;

  initial
  begin

    {a, b, c} = 3'b0;
    #1000 $finish;
  end
  
  always
  begin
    #10
    {a, b, c} = {a, b, c} + 1'b1;
  end
  binary_adder adder (a, b, c, sum, carry);
endmodule