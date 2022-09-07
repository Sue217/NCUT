/*
    file: memory.v
    author: Jingbo Su
    created: August 2022
*/

module Data_Memory (
  output wire[31:0] ret,
  input wire[31:0] write,
  input wire[31:0] pos,
  input wire en,
  input wire clk
);
    

localparam width = 6'b111111;
reg[7:0] mem[0:width];

//* for test
initial begin
  $readmemh("../../../../test/data.in", mem);
end

assign ret = {mem[pos], mem[pos + 1], mem[pos + 2], mem[pos + 3]}; // jr: (PC) <- (rs)

always @(negedge clk) begin
  if (en) begin
    // write data into memory
    // Big end [v0, v1, v2, v3]
    mem[pos + 0] <= write[31:24];
    mem[pos + 1] <= write[23:16];
    mem[pos + 2] <= write[15:8];
    mem[pos + 3] <= write[7:0];
  end
end

endmodule

module Instructon_Memory (
  output wire[31:0] read,
  input wire[31:0] pos
);

localparam integer width = 6'b111111;
reg[7:0] mem[0:width];

// read data from memory
assign read = {mem[pos], mem[pos + 1], mem[pos + 2], mem[pos + 3]};

//* for test
initial begin
  $readmemh("../../../../test/ins.in", mem);
end

endmodule