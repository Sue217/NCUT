`timescale 1ns/1ps

module assignment_2 (
  input clk,
  output reg[15:0] row,
  output reg[3:0] column
);

reg [15:0] row;
reg [3:0] column = 0;

integer total = 0;  // word library number
integer counter = 0; // counter for analog clock signal

always @(posedge clk) begin
  counter = counter + 1;
  if (counter == 5000) begin  // 0.5s
    counter = 0;
    total = total + 1;
  end
  if (total == 3) begin
    total = 0;
  end
end

always @(negedge clk) begin
  case (total)
    0: begin
      case (column)
        4'd0: begin row =  16'b00001000_00100000; end
        4'd1: begin row =  16'b00001000_00101000; end
        4'd2: begin row =  16'b11111111_11111110; end
        4'd3: begin row =  16'b00001000_00100000; end
        4'd4: begin row =  16'b00001010_00100000; end
        4'd5: begin row =  16'b00000010_00010000; end
        4'd6: begin row =  16'b00111111_11111000; end
        4'd7: begin row =  16'b00000010_00010000; end
        4'd8: begin row =  16'b00000010_00010000; end
        4'd9: begin row =  16'b00100010_00011000; end
        4'd10: begin row = 16'b00100100_00010110; end
        4'd11: begin row = 16'b01000100_00010010; end
        4'd12: begin row = 16'b00001000_00010000; end
        4'd13: begin row = 16'b00010000_00010000; end
        4'd14: begin row = 16'b00100000_01010000; end
        4'd15: begin row = 16'b01000000_00100000; end
      endcase
    end

    1: begin
      case (column)
        4'd0: begin row =  16'b00100000_01000000; end
        4'd1: begin row =  16'b00010000_01001000; end
        4'd2: begin row =  16'b00010011_11111100; end
        4'd3: begin row =  16'b11111100_01000000; end
        4'd4: begin row =  16'b00000011_11111000; end
        4'd5: begin row =  16'b01001000_01000000; end
        4'd6: begin row =  16'b01001111_11111110; end
        4'd7: begin row =  16'b01001000_00001000; end
        4'd8: begin row =  16'b01001011_11111100; end
        4'd9: begin row =  16'b00010010_00001000; end
        4'd10: begin row = 16'b00010011_11111000; end
        4'd11: begin row = 16'b00011110_00001000; end
        4'd12: begin row = 16'b11100011_11111000; end
        4'd13: begin row = 16'b01000010_00001000; end
        4'd14: begin row = 16'b00000010_00101000; end
        4'd15: begin row = 16'b00000010_00010000; end
      endcase
    end

    2: begin
      case (column)
      4'd0: begin row =  16'b00100000_01010000; end
      4'd1: begin row =  16'b00100000_01001000; end
      4'd2: begin row =  16'b00101111_11111110; end
      4'd3: begin row =  16'b00100000_01000000; end
      4'd4: begin row =  16'b00100111_11111100; end
      4'd5: begin row =  16'b11111100_01000100; end
      4'd6: begin row =  16'b00100111_11111100; end
      4'd7: begin row =  16'b00100100_01000100; end
      4'd8: begin row =  16'b00100111_11111100; end
      4'd9: begin row =  16'b00100100_01000100; end
      4'd10: begin row = 16'b00100000_00010000; end
      4'd11: begin row = 16'b00101111_11111110; end
      4'd12: begin row = 16'b00100010_00010000; end
      4'd13: begin row = 16'b00100001_00010000; end
      4'd14: begin row = 16'b00100000_01010000; end
      4'd15: begin row = 16'b00100000_00100000; end
      endcase
    end
  endcase
  
  column = column + 4'd1;
  if (column == 4'd16) begin
    column = 4'd0;
  end
end

endmodule