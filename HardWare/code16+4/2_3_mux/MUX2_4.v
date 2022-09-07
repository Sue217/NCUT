//Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
//Date        : Tue Jul  5 22:01:05 2022
//Host        : DESKTOP-D18RA48 running 64-bit major release  (build 9200)
//Command     : generate_target MUX2_4_wrapper.bd
//Design      : MUX2_4_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module MUX2_4_wrapper
   (D0_0,
    D0_1,
    D1_0,
    D1_1,
    S_0,
    S_1,
    Y_0);
  input D0_0;
  input D0_1;
  input D1_0;
  input D1_1;
  input S_0;
  input S_1;
  output Y_0;

  wire D0_0;
  wire D0_1;
  wire D1_0;
  wire D1_1;
  wire S_0;
  wire S_1;
  wire Y_0;

  MUX2_4 MUX2_4_i
       (.D0_0(D0_0),
        .D0_1(D0_1),
        .D1_0(D1_0),
        .D1_1(D1_1),
        .S_0(S_0),
        .S_1(S_1),
        .Y_0(Y_0));
endmodule
