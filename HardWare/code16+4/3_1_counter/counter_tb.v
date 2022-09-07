`timescale 1ns / 1ps

module counter_tb;

  reg clk, rst;
  wire [7:0] Q;
  counter counter_tb(
    .clk(clk),
    .rst(rst),
    .Q(Q)
  );
  initial
  begin
    clk = 0;
    rst = 0;
    #10 rst = 1;
    forever #10 clk = ~clk;
  end
endmodule
