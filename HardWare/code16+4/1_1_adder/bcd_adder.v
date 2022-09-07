`timescale 1ns / 1ps

module bcd_adder (a, b, cin, sum, cout);
  input a, b;
  input cin;
  output sum;
  output cout;
  reg t;
  reg sum;
  reg cout;  

  always @(a, b, cin)
  begin
    t = a + b + cin; 
    if(t > 9) 
	  begin
      t = t + 6;        // add 6, if result is more than 9.
      cout = 1;         // set the carry
      sum = t;   
    end
    else    
	  begin
      cout = 0;
      sum = t;
    end
  end     
endmodule