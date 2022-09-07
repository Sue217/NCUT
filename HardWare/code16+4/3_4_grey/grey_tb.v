`timescale 1ns / 1ps

module grey_tb;

  reg [7:0] bit;
  wire [7:0] grey;
  grey testbench(
    .bit(bit),
    .grey(grey)
  );

  initial
  begin
    bit = 8'b01100100; 
  end

  always #100 bit[0] = ~bit[0];
  always #100 bit[1] = ~bit[1];
  always #100 bit[2] = ~bit[2];
  always #100 bit[3] = ~bit[3];
  always #100 bit[4] = ~bit[4];
  always #100 bit[5] = ~bit[5];
  always #100 bit[6] = ~bit[6];
  always #100 bit[7] = ~bit[7];
endmodule
