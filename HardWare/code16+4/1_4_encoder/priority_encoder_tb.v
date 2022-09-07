`timescale 1ns / 1ps

module priority_encoder_tb;
  reg [3:0] D;
  wire [1:0] ENC;
  wire VLD;
  integer counter;

  priority_encoder encoder(
    .D(D),
    .ENC(ENC),
    .VLD(VLD)
  );

  initial
  begin
    D = 0;
    counter = 0;
    for (counter = 1; counter <= 16; counter = counter + 1) begin
      #5 D = counter;
    end
  end

  initial #100 $finish;
endmodule