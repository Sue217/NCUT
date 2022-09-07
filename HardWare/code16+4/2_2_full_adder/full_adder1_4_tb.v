`timescale 1ns / 1ps

module full_adder1_4_tb;

  reg [3:0] in1, in2;
  reg cin;
  wire [3:0] s;
  wire cout;
  
  reg [2:0] counter = 3'd0;
  
  full_adder1_4_wrapper adder(
    .in1_0(in1[0]),
    .in1_1(in1[1]),
    .in1_2(in1[2]),
    .in1_3(in1[3]),
    .in2_0(in2[0]),
    .in2_1(in2[1]),
    .in2_2(in2[2]),
    .in2_3(in2[3]),
    .cin_0(cin),
    .sum_0(s[0]),
    .sum_1(s[1]),
    .sum_2(s[2]),
    .sum_3(s[3]),
    .cout_0(cout)
  );
  
  initial
  begin
    in1 = 4'b0;
    in2 = 4'b0;
    cin = 1'b0;
    #100;
    
    for (counter = 0; counter < 8; counter = counter + 1'b1) begin
      {in1, in2, cin} = {in1, in2, cin} + 1'b1;
    #20;
    end
  end
endmodule
