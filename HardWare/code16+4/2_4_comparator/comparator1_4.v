`timescale 1ns / 1ps

module comparator1_4(
  a, b, greater, equal, less
);

  input [3:0] a, b;
  output [3:0] greater, equal, less;
  
  wire [3:0] gt, eq, lt;
  
  bit_comparator_0 u0 (
    .a(a[0]),
    .b(b[0]),
    .greater(gt[0]),
    .equal(eq[0]),
    .less(lt[0])
  );
  bit_comparator_0 u1 (
    .a(a[1]),
    .b(b[1]),
    .greater(gt[1]),
    .equal(eq[1]),
    .less(lt[1])
  );
  bit_comparator_0 u2 (
    .a(a[2]),
    .b(b[2]),
    .greater(gt[2]),
    .equal(eq[2]),
    .less(lt[2])
  );
  bit_comparator_0 u3 (
    .a(a[3]),
    .b(b[3]),
    .greater(gt[3]),
    .equal(eq[3]),
    .less(lt[3])
  );
  
  assign greater = gt[3] | (eq[3] & gt[2]) | (eq[3] & eq[2] & gt[1]) | (eq[3] & eq[2] & eq[1] & gt[0]);
  assign equal = eq[3] & eq[2] & eq[1] & eq[0];
  assign less = lt[3] | (eq[3] & lt[2]) | (eq[3] & eq[2] & lt[1]) | (eq[3] & eq[2] & eq[1] & lt[0]);
endmodule