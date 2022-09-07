`timescale 1ns / 1ps

module seven_seg_tb;
    reg [3:0] bcd;
    wire [6:0] seg;
    integer i;

    seven_seg seg7 (
      .bcd(bcd), 
      .seg(seg)
    );

    initial
    begin
      for(i = 0; i < 16; i = i + 1)
      begin
        bcd = i;
        #50;
      end 
    end
endmodule
