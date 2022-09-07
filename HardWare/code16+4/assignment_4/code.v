`timescale 1ns / 1ps

module assignment_4 (
  input clk,
  input rst,
  input [7:0] in,
  output [7:0] seg,
  output [2:0] sel,
  output [7:0] out
);

reg[7:0] seg, out = 8'b00000000;
reg state;
reg[2:0] counter = 0;

assign sel = 0;

reg[1:0] current, next;
reg seq; // read sequence number

integer i;
// state
parameter Zero = 2'b00;
parameter One = 2'b01;
parameter Two = 2'b11;

// Update state
always @(posedge clk) begin
  counter = 0;
  if (rst == 1) begin
    current = next;
    i = 0;
  end
  else begin
    current = Zero;
    for(i = 0; i <= 7; i = i + 1) begin
      seq = in[i];  
      case (current)
        Zero: begin
          if (seq == 0) begin
            next = One;
            state = 0;
          end
          else begin
            next = Zero;  // self loop
            state = 0;
          end
        end
        One: begin
          if (seq == 0) begin
            next = Two;
            state = 0;
          end
          else begin
            next = Zero;
            state = 0;
          end
        end
        Two: begin
          if (seq == 1) begin
            next = Zero;
            state = 1;
            counter = counter + 1;
          end
          else begin
            next = Two; // self loop
            state = 0;
          end
        end
      endcase
      current = next;
      out[i] = state;
    end
    case (counter) // seven segment digit display
      3'd0: seg <= 8'b00111111;
      3'd1: seg <= 8'b00000110;
      3'd2: seg <= 8'b01011011;
      3'd3: seg <= 8'b01001111;
      3'd4: seg <= 8'b01100110;
      3'd5: seg <= 8'b01101101;
      3'd6: seg <= 8'b01111101;
      3'd7: seg <= 8'b00000111;
      default: seg <= 8'b00000000;
    endcase
  end
end

endmodule