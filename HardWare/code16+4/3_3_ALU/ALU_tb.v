`timescale 1ns / 1ps

module ALU_tb;

  reg en, clk;
  reg [2:0] opcode;
  reg [7:0] x, y;
  wire [8:0] z;

  ALU testbench(
    .en(en),
    .clk(clk),
    .opcode(opcode),
    .x(x),
    .y(y),
    .z(z)
  );

  initial
  begin
    en = 1;
    clk = 0;
    opcode = 3'b000;
    x = 8'b00110011;
    y = 8'b10101010;
  end
  always #50 opcode[0] = ~opcode[0];
  always #50 opcode[1] = ~opcode[1];
  always #50 opcode[2] = ~opcode[2];
endmodule
