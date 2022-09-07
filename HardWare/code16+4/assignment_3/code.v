//Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
//Date        : Sun Sep  4 08:33:41 2022
//Host        : DESKTOP-D18RA48 running 64-bit major release  (build 9200)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (a_0,
    a_1,
    b_0,
    b_1,
    c_0,
    carry_0,
    sum_0,
    sum_1);
  input a_0;
  input a_1;
  input b_0;
  input b_1;
  input c_0;
  output carry_0;
  output sum_0;
  output sum_1;

  wire a_0;
  wire a_1;
  wire b_0;
  wire b_1;
  wire c_0;
  wire carry_0;
  wire sum_0;
  wire sum_1;

  design_1 design_1_i
       (.a_0(a_0),
        .a_1(a_1),
        .b_0(b_0),
        .b_1(b_1),
        .c_0(c_0),
        .carry_0(carry_0),
        .sum_0(sum_0),
        .sum_1(sum_1));
endmodule
