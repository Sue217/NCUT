`timescale 1ns / 1ps

module counter(
  input clk, rst,
  output reg [7:0] Q
);
  always @(posedge clk or negedge rst)
  begin
    if(!rst)
      Q <= 0;
    else
      begin
        if(Q <= 99)
          Q <= Q+1;
        else
          Q <= 0;
      end
  end
endmodule
