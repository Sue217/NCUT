`timescale 1ns / 1ps

module full_adder_tb;

  reg in1;
  reg in2;
  reg cin;

  wire sum;
  wire cout;

  reg [2:0] i = 3'd0;

  full_adder adder (
    .in1(in1), 
    .in2(in2), 
    .cin(cin), 
    .sum(sum), 
    .cout(cout)
    );

  initial
  begin

    in1 = 1'b0;
    in2 = 1'b0;
    cin = 1'b0;
    
    #100;

    for (i = 0; i < 8; i = i + 1'b1) begin
      {in1,in2,cin} = {in1,in2,cin} + 1'b1;

    #20;

    end

  end      

endmodule