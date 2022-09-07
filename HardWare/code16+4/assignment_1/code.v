`timescale 1ns / 1ps

/*
        ____    1
    0   |  |    2
        ----    6
    5   |  |    3
        ----    4
*/

module assignment_1 (
  input clk,
  output reg[2:0] sel,
  output reg[7:0] seg
);

initial begin
  sel = 3'b000;
end

always @(posedge clk)
  begin
    case(sel)
      3'b000 : begin seg = 8'b00000110; end  // 1
      3'b001 : begin seg = 8'b00111111; end  // 0
      3'b010 : begin seg = 8'b00000110; end  // 1
    endcase
    #1000

    sel = sel + 1'd1;
    if (sel > 3'd2) begin
      sel = 3'd0;
    end
    #1000;
  end

endmodule