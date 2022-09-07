`timescale 1ns / 1ps

module half_adder_tb;
  reg r_a = 0;
  reg r_b = 0;
  wire t_sum;
  wire t_carry;
   
  half_adder adder (
     .a(r_a),
     .b(r_b),
     .sum(t_sum),
     .carry(t_carry)
     );
 
  initial
    begin
      r_a = 1'b0;
      r_b = 1'b0;
      #10;
      r_a = 1'b0;
      r_b = 1'b1;
      #10;
      r_a = 1'b1;
      r_b = 1'b0;
      #10;
      r_a = 1'b1;
      r_b = 1'b1;
      #10;
    end 
 
endmodule