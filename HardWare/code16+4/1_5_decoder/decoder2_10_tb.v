`timescale 1ns / 1ps

module decoder2_10_tb;
  reg [3:0] addr;
  wire [15:0] dec;
  integer counter = 4'd0;

  decoder2_10 decoder (
    .addr(addr),
    .dec(dec)
  );

  initial
  begin
    addr = 0;
    counter = 0;

    for (counter = 1; counter <= 16; counter = counter + 1) begin
      #10 addr = counter;
    end
  end

  initial #100 $finish;
endmodule