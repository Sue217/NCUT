`timescale 1ns / 1ps

module splitter2_4_tb;

    reg in;
    reg [1:0] sel;
    wire [3:0] out;
    
    splitter2_4 demux(
      .in(in),
      .sel(sel),
      .out(out)
    );
    
    initial
    begin
      {in, sel} = 3'd0;
      #100 $finish;
    end
    
    always
    begin
      #10
      {in, sel} = {in, sel} + 1'b1;
    end
    
endmodule
