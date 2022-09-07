`timescale 1ns / 1ps

module assignment_2_tb();

wire[15:0] row;
wire[3:0] column;
reg clk;

assignment_2 run(
  .clk(clk),
  .row(row),
  .column(column)
);

initial begin
  clk=0;
end

always #0.1 clk=~clk;

endmodule