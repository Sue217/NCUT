//Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
//Date        : Tue Jul  5 21:30:34 2022
//Host        : DESKTOP-D18RA48 running 64-bit major release  (build 9200)
//Command     : generate_target full_adder1_4_wrapper.bd
//Design      : full_adder1_4_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module full_adder1_4_wrapper
   (cin_0,
    cout_0,
    in1_0,
    in1_1,
    in1_2,
    in1_3,
    in2_0,
    in2_1,
    in2_2,
    in2_3,
    sum_0,
    sum_1,
    sum_2,
    sum_3);
  input cin_0;
  output cout_0;
  input in1_0;
  input in1_1;
  input in1_2;
  input in1_3;
  input in2_0;
  input in2_1;
  input in2_2;
  input in2_3;
  output sum_0;
  output sum_1;
  output sum_2;
  output sum_3;

  wire cin_0;
  wire cout_0;
  wire in1_0;
  wire in1_1;
  wire in1_2;
  wire in1_3;
  wire in2_0;
  wire in2_1;
  wire in2_2;
  wire in2_3;
  wire sum_0;
  wire sum_1;
  wire sum_2;
  wire sum_3;

  full_adder1_4 full_adder1_4_i
       (.cin_0(cin_0),
        .cout_0(cout_0),
        .in1_0(in1_0),
        .in1_1(in1_1),
        .in1_2(in1_2),
        .in1_3(in1_3),
        .in2_0(in2_0),
        .in2_1(in2_1),
        .in2_2(in2_2),
        .in2_3(in2_3),
        .sum_0(sum_0),
        .sum_1(sum_1),
        .sum_2(sum_2),
        .sum_3(sum_3));
endmodule
