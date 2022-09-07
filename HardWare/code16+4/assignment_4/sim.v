`timescale 1ns / 1ps

module assignment_4_tb();

reg clk;
reg rst = 0;
reg [7:0] in;
wire [7:0] seg;
wire [2:0] sel;
wire [7:0] out;

assignment_4 run (
  .clk(clk),
  .rst(rst),
  .in(in),
  .seg(seg),
  .sel(sel),
  .out(out)
);

initial begin
  clk = 1'b0;
  forever #10 clk = ~clk;
end
    
initial begin
  #100 in <= 8'b00100011;
  #100 rst = 1'b1;
  #50 rst = 1'b0;
  #100 rst = 1'b1;
  #50 rst = 1'b0;
  #100 $stop;
end

endmodule