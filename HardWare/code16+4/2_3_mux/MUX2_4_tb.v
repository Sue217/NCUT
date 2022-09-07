`timescale 1ns / 1ps

module MUX2_4_tb;

  reg [3:0] a;
  reg [1:0] s;
  wire out;
  
  MUX2_4_wrapper MUX(
    .D0_0(a[0]),
    .D0_1(a[1]),
    .D1_0(a[2]),
    .D1_1(a[3]),
    .S_0(s[0]),
    .S_1(s[1]),
    .Y_0(out)
  );
  
  initial
  begin
    a = 4'b1010;
    s = 2'b00; #100
    s = 2'b01; #100
    s = 2'b10; #100
    s = 2'b11; #100
    $stop;
  end
endmodule
