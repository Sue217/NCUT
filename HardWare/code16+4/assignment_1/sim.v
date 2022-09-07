`timescale 1ns / 1ps

module assignment_1_tb ();

reg clk;
wire[7:0] seg;
wire[2:0] sel;

assignment_1 run (
  .clk(clk),
  .sel(sel),
  .seg(seg)
);

initial begin
  clk = 0;
end

always #10 clk = ~clk;

endmodule