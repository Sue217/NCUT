//Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
//Date        : Tue Jul  5 20:41:36 2022
//Host        : DESKTOP-D18RA48 running 64-bit major release  (build 9200)
//Command     : generate_target adder1_4_bcd.bd
//Design      : adder1_4_bcd
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "adder1_4_bcd,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=adder1_4_bcd,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=4,numReposBlks=4,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}" *) (* HW_HANDOFF = "adder1_4_bcd.hwdef" *) 
module adder1_4_bcd
   (a_0,
    a_1,
    a_2,
    a_3,
    b_0,
    b_1,
    b_2,
    b_3,
    cin_0,
    cout_0,
    sum_0,
    sum_1,
    sum_2,
    sum_3);
  input a_0;
  input a_1;
  input a_2;
  input a_3;
  input b_0;
  input b_1;
  input b_2;
  input b_3;
  input cin_0;
  output cout_0;
  output sum_0;
  output sum_1;
  output sum_2;
  output sum_3;

  wire a_0_1;
  wire a_1_1;
  wire a_2_1;
  wire a_3_1;
  wire b_0_1;
  wire b_1_1;
  wire b_2_1;
  wire b_3_1;
  wire bcd_adder_0_cout;
  wire bcd_adder_0_sum;
  wire bcd_adder_1_cout;
  wire bcd_adder_1_sum;
  wire bcd_adder_2_cout;
  wire bcd_adder_2_sum;
  wire bcd_adder_3_cout;
  wire bcd_adder_3_sum;
  wire cin_0_1;

  assign a_0_1 = a_0;
  assign a_1_1 = a_1;
  assign a_2_1 = a_2;
  assign a_3_1 = a_3;
  assign b_0_1 = b_0;
  assign b_1_1 = b_1;
  assign b_2_1 = b_2;
  assign b_3_1 = b_3;
  assign cin_0_1 = cin_0;
  assign cout_0 = bcd_adder_3_cout;
  assign sum_0 = bcd_adder_0_sum;
  assign sum_1 = bcd_adder_1_sum;
  assign sum_2 = bcd_adder_2_sum;
  assign sum_3 = bcd_adder_3_sum;
  adder1_4_bcd_bcd_adder_0_0 bcd_adder_0
       (.a(a_0_1),
        .b(b_0_1),
        .cin(cin_0_1),
        .cout(bcd_adder_0_cout),
        .sum(bcd_adder_0_sum));
  adder1_4_bcd_bcd_adder_0_1 bcd_adder_1
       (.a(a_1_1),
        .b(b_1_1),
        .cin(bcd_adder_0_cout),
        .cout(bcd_adder_1_cout),
        .sum(bcd_adder_1_sum));
  adder1_4_bcd_bcd_adder_0_2 bcd_adder_2
       (.a(a_2_1),
        .b(b_2_1),
        .cin(bcd_adder_1_cout),
        .cout(bcd_adder_2_cout),
        .sum(bcd_adder_2_sum));
  adder1_4_bcd_bcd_adder_0_3 bcd_adder_3
       (.a(a_3_1),
        .b(b_3_1),
        .cin(bcd_adder_2_cout),
        .cout(bcd_adder_3_cout),
        .sum(bcd_adder_3_sum));
endmodule
