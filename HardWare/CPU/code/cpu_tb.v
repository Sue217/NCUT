/*
    file: cpu_tb.v
    author: Jingbo Su
    created: August 2022
*/

`timescale 1ns / 1ps

module cpu_tb();
reg clk, rst;

wire[2:0] sel;
wire[7:0] seg;

initial begin
  clk = 1;
  rst = 0;
  #1 rst = 1;
  #999 $finish;
end
  
always #1 clk = ~clk;
  
CPU cpu(
  .clk(clk),
  .rst(rst),
  .sel(sel),
  .seg(seg)
);

endmodule
