# Summer Hardware Project

<center><img src="/Users/sudo/Pictures/school/school_title.jpeg" alt="school_title" style="zoom:80%;" /></center>



<center><img src="/Users/sudo/Pictures/school/ncut_icon.png" alt="ncut_icon" style="zoom:75%;" /></center>




<center><div style='height:2mm;'></div><div style="font-size:15pt;">Author: Jingbo Su</div></center>
<center><span style="font-size:12pt;line-height:9mm"><i>North China University of Technology</i></span>
<div style="page-break-after: always;"></div>

# 16 problems



## Part I

### Adder1

#### BCD Adder

> bcd_adder.v

```verilog
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
```

> bcd_adder_tb.v

```verilog
`timescale 1ns / 1ps

module bcd_adder_tb;
    
  reg a;
  reg b;
  reg cin;
  wire sum;
  wire cout;

  bcd_adder adder (
    .a(a), 
    .b(b), 
    .cin(cin), 
    .sum(sum), 
    .cout(cout)
  );

  initial
  begin
    a = 0;  b = 0;  cin = 0;   #100;
    a = 6;  b = 9;  cin = 0;   #100;
    a = 3;  b = 3;  cin = 1;   #100;
    a = 4;  b = 5;  cin = 0;   #100;
    a = 8;  b = 2;  cin = 0;   #100;
    a = 9;  b = 9;  cin = 1;   #100;
  end    
endmodule
```

<img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_1_adder/bcd_adder.png" alt="bcd_adder" style="zoom:100%;" />

![GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/1_1_adder/GUI.png)

#### Binary Adder

> binary_adder.v

```verilog
`timescale 1ns / 1ps

module binary_adder (
  input a,
  input b,
  input c,
  output sum,
  output carry
);
  assign sum = a ^ b ^ c;
  assign carry = (a & b) | (a & c) | (b & c);
endmodule
```

> binary_adder_tb.v

```verilog
`timescale 1ns / 1ps

module binary_adder_tb;
    
  reg a, b, c;
  wire sum, carry;
  initial
  begin
    {a, b, c} = 3'b0;
    #1000 $finish;
  end
  
  always
  begin
    #10
    {a, b, c} = {a, b, c} + 1'b1;
  end
  binary_adder adder (a, b, c, sum, carry);
endmodule
```

<img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_1_adder/binary_adder.png" alt="binary_adder" style="zoom:100%;" />

![GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/1_1_adder/GUI.png)

### Adder2

#### Full Adder

> full_adder.v

```verilog
`timescale 1ns / 1ps

module full_adder (in1, in2, cin, sum, cout);
    
  input  in1, in2, cin;
  output  sum, cout;
  assign sum  = (in1 ^ in2) ^ cin;
  assign cout = (in1 & in2) | (in2 & cin) | (cin & in1);
endmodule
```

> full_adder_tb.v

```verilog
`timescale 1ns / 1ps

module full_adder_tb;
    
  reg in1;
  reg in2;
  reg cin;
  wire sum;
  wire cout;
  reg [2:0] i = 3'd0;
    
  full_adder adder (
    .in1(in1), 
    .in2(in2), 
    .cin(cin), 
    .sum(sum), 
    .cout(cout)
  );
    
  initial
  begin
    in1 = 1'b0;
    in2 = 1'b0;
    cin = 1'b0;
    // reset to finish
    #100;
    for (i = 0; i < 8; i = i + 1'b1) begin
      {in1,in2,cin} = {in1,in2,cin} + 1'b1;
    #20;
    end
  end      
endmodule
```



> <img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_2_adder/full_adder.png" alt="full_adder" style="zoom:100%;" />
>
> ![GUI_full](/Users/sudo/Desktop/Courses/summer_hardware/code/1_2_adder/GUI_full.png)

#### Half Adder

> half_adder.v

```verilog
`timescale 1ns / 1ps

module half_adder (a, b, sum, carry);
    
  input  a, b;
  output sum, carry;
    
  assign sum = a ^ b;
  assign carry = a & b;
endmodule
```

> half_adder_tb.v

```verilog
`timescale 1ns / 1ps

module half_adder_tb;
    
  reg r_a = 0, r_b = 0;
  wire t_sum, t_carry;
    
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
```

<img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_2_adder/half_adder.png" alt="half_adder" style="zoom:100%;" />

![GUI_half](/Users/sudo/Desktop/Courses/summer_hardware/code/1_2_adder/GUI_half.png)

### 2:1 MUX

> MUX2_1.v

```verilog
`timescale 1ns / 1ps

module MUX2_1 (Y, D0, D1, S);
    
input D0, D1, S;
output Y;

wire T1, T2, Sbar;

and (T1, D1, S), (T2, D0, Sbar);
not (Sbar, S);
or (Y, T1, T2);

endmodule
```

> MUX2_1_tb.v

```verilog
`timescale 1ns / 1ps

module MUX2_1_tb;
  wire out;
  reg d0, d1, s;
  MUX2_1 mux (.Y(out), .D0(d0), .D1(d1), .S(s));
  
  initial
  begin
    d0 = 1'b0;
    d1 = 1'b0;
    s = 1'b0;
    #100;
  end
  
  always #40 d0 = ~d0;
  always #20 d1 = ~d1;
  always #10 s = ~s;

endmodule
```

<img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_3_mux/MUX2_1.png" alt="MUX2_1" style="zoom:100%;" />

![GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/1_3_mux/GUI.png)

### Encoder

#### Priority Encoder

> priority_encoder.v

```verilog
`timescale 1ns / 1ps

module priority_encoder (
  input [3:0] D,
  output [1:0] ENC,
  output VLD
);

  assign ENC[0] = (~D[2] & D[1]) | D[3];
  assign ENC[1] = D[2] | D[3];
  assign VLD = D[0] | D[1] | D[2] | D[3];
endmodule
```

> priority_encoder_tb.v

```verilog
`timescale 1ns / 1ps

module priority_encoder_tb;
    
  reg [3:0] D;
  wire [1:0] ENC;
  wire VLD;
  integer counter;

  priority_encoder encoder(
    .D(D),
    .ENC(ENC),
    .VLD(VLD)
  );

  initial
  begin
    D = 0;
    counter = 0;
    for (counter = 1; counter <= 16; counter = counter + 1) begin
      #5 D = counter;
    end
  end
  initial #100 $finish;
endmodule
```

<img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_4_encoder/priority_encoder.png" alt="priority_encoder" style="zoom:100%;" />

![GUI_priority](/Users/sudo/Desktop/Courses/summer_hardware/code/1_4_encoder/GUI_priority.png)

#### BCD Encoder

> bcd_encoder.v

```verilog
`timescale 1ns / 1ps

module bcd_encoder(en, cin, cout);
    
  input en;
   input [9:0] cin;
  output reg [3:0] cout;

  always @(cin, en)
    begin
      if (en == 0)
        cout = 4'bXXX;
       else
        case(cin)
          10'b0000000001: cout = 4'b0000;    // 0
          10'b0000000010: cout = 4'b0001;    // 1
          10'b0000000100: cout = 4'b0010;    // 2
          10'b0000001000: cout = 4'b0011;    // 3
          10'b0000010000: cout = 4'b0100;    // 4
          10'b0000100000: cout = 4'b0101;    // 5
          10'b0001000000: cout = 4'b0110;    // 6
          10'b0010000000: cout = 4'b0111;    // 7
          10'b0100000000: cout = 4'b1000;    // 8
          10'b1000000000: cout = 4'b1001;    // 9
          default: cout = 4'bX;
        endcase
    end
endmodule
```

> bcd_encoder_tb.v

```verilog
`timescale 1ns / 1ps

module bcd_encoder_tb;
    
  reg en;
  reg [9:0] cin;
  wire [3:0] cout;
  bcd_encoder encoder(en, cin, cout);
  
  initial
  begin
    en = 1; cin = 10'b0000000001; #50
    en = 1; cin = 10'b0000000010; #50
    en = 1; cin = 10'b0000000100; #50
    en = 1; cin = 10'b0000001000; #50
    en = 1; cin = 10'b0000010000; #50
    en = 1; cin = 10'b0000100000; #50
    en = 1; cin = 10'b0001000000; #50
    en = 1; cin = 10'b0010000000; #50
    en = 1; cin = 10'b0100000000; #50
    en = 1; cin = 10'b1000000000; #50
    $finish;
  end
endmodule
```

![bcd_encoder](/Users/sudo/Desktop/Courses/summer_hardware/code/1_4_encoder/bcd_encoder.png)

![GUI_bcd](/Users/sudo/Desktop/Courses/summer_hardware/code/1_4_encoder/GUI_bcd.png)

#### 4 to 2 Encoder

> encoder4_2.v

```verilog
`timescale 1ns / 1ps

module encoder4_2(
  input d0, d1, d2, d3,
  output a0, a1
);
  wire x, y, z;
  not g1(x, d2);        // x = ~d2
  and g2(y, x, d1);     // y = x & d1
  or g3(a0, y, d3);     // a0 = y | d3
  or g4(a1, d2, d3);    // a1 = d2 | d3
endmodule
```

> encoder4_2_tb.v

```verilog
`timescale 1ns / 1ps
module encoder4_2_tb;
  reg d0, d1, d2, d3;
  wire a0, a1;

  encoder4_2 encoder (
    .d0(d0),
    .d1(d1),
    .d2(d2),
    .d3(d3),
    .a0(a0),
    .a1(a1)
  );
  
  initial
  begin
    d0 = 1; d1 = 0; d2 = 0; d3 = 0;
    #100; d0 = 0; d1 = 1; d2 = 0; d3 = 0;
    #100; d0 = 0; d1 = 0; d2 = 1; d3 = 0;
    #100; d0 = 0; d1 = 0; d2 = 0; d3 = 1;
  end
endmodule
```

<img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_4_encoder/encoder4_2.png" alt="encoder4_2" style="zoom:100%;" />

![GUI4_2](/Users/sudo/Desktop/Courses/summer_hardware/code/1_4_encoder/GUI4_2.png)

### Decoder

#### 2 to 4 Decoder

> decoder2_4.v

```verilog
`timescale 1ns / 1ps

module decoder2_4(en, a, b, y);
    
  input en, a, b;
  output [3:0] y;

  wire n_en, n_a, n_b;
  not g0(n_en, en);
  not g1(n_a, a);
  not g2(n_b, b);

  assign y[0] = ~(n_en & n_a & n_b);
  assign y[1] = ~(n_en & n_a & b);
  assign y[2] = ~(n_en & a & n_b);
  assign y[3] = ~(n_en & a & b);

endmodule
```

> decoder2_4_tb.v

```verilog
`timescale 1ns / 1ps

module decoder2_4_tb;

  reg a, b, en;
  wire [3:0] y;
  decoder2_4 decoder(en, a, b, y);
  
  initial
  begin
    en = 1; a = 1'b0; b = 1'b0; #50
    en = 0; a = 0; b = 0; #50
    en = 0; a = 0; b = 1; #50
    en = 0; a = 1; b = 0; #50
    en = 0; a = 1; b = 1; #50
    $finish;
  end
endmodule
```

<img src="/Users/sudo/Desktop/Courses/summer_hardware/code/1_5_decoder/decoder2_4.png" alt="decoder2_4" style="zoom:100%;" />

![GUI_decoder2_4](/Users/sudo/Desktop/Courses/summer_hardware/code/1_5_decoder/GUI_decoder2_4.png)

#### BCD Decoder

> decoder2_10.v

```verilog
`timescale 1ns / 1ps

module decoder2_10 (
  input [3:0] addr,
  output [15:0] dec
);

  assign dec[0] = ~addr[0] & ~addr[1] & ~addr[2] & ~addr[3];
  assign dec[1] = ~addr[0] & ~addr[1] & ~addr[2] & addr[3];
  assign dec[2] = ~addr[0] & ~addr[1] & addr[2] & ~addr[3];
  assign dec[3] = ~addr[0] & ~addr[1] & addr[2] & addr[3];
  assign dec[4] = ~addr[0] & addr[1] & ~addr[2] & ~addr[3];
  assign dec[5] = ~addr[0] & addr[1] & ~addr[2] & addr[3];
  assign dec[6] = ~addr[0] & addr[1] & addr[2] & ~addr[3];
  assign dec[7] = ~addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[8] = addr[0] & ~addr[1] & ~addr[2] & ~addr[3];
  assign dec[9] = addr[0] & ~addr[1] & ~addr[2] & addr[3];
  assign dec[10] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[11] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[12] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[13] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[14] = addr[0] & addr[1] & addr[2] & addr[3];
  assign dec[15] = addr[0] & addr[1] & addr[2] & addr[3];
endmodule
```

> decoder2_10_tb.v

```verilog
`timescale 1ns / 1ps

module decoder2_10_tb;
    
  reg [3:0] addr;
  wire [15:0] dec;
  integer counter = 4'd0;

  decoder2_10 decoder (
    .addr(addr),
    .dec(dec)
  );

  initial
  begin
    addr = 0;
    counter = 0;
    for (counter = 1; counter <= 16; counter = counter + 1) begin
      #10 addr = counter;
    end
  end
  initial #100 $finish;
endmodule
```

![decoder2_10](/Users/sudo/Desktop/Courses/summer_hardware/code/1_5_decoder/decoder2_10.png)

![GUI_decoder2_10](/Users/sudo/Desktop/Courses/summer_hardware/code/1_5_decoder/GUI_decoder2_10.png)

### Comparator

> bit_comparator.v

```verilog
`timescale 1ns / 1ps

module bit_comparator(
  input a,
  input b,
  output greater,
  output less,
  output equal
);

  assign greater = (a & 1) & (~(b | 0));
  assign less = (~(a | 0)) & (b & 1);
  assign equal = a ^ (~b);
endmodule
```

> bit_comparator_tb.v

```verilog
`timescale 1ns / 1ps

module bit_comparator_tb;
    
  reg a;
  reg b;
  wire greater;
  wire less;
  wire equal;
  reg [1:0] counter;

  bit_comparator comparator(
    .a(a),
    .b(b),
    .greater(greater),
    .less(less),
    .equal(equal)
  );

  initial
  begin
    a = 0;
    b = 0;
    counter = 0;
  end

  always @(a or b) begin

    for (counter = 0; counter < 4; counter = counter + 1)
      #100 {a, b} = counter;
      #100 $stop;
    end
endmodule

```

![bit_comparator](/Users/sudo/Desktop/Courses/summer_hardware/code/1_6_comparator/bit_comparator.png)

![GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/1_6_comparator/GUI.png)

### De-MUX

> two_bit_splitter

```verilog
`timescale 1ns / 1ps

module two_bit_splitter (
  input s,
  input d,
  output y0,
  output y1
);

  not(n_s, s);          // n_s = ~s;
  and(y0, n_s, d);      // y0 = n_s & d;
  and(y1, s, d);        // y1 = s & d;
endmodule
```



>two_bit_splitter_tb.v

```verilog
`timescale 1ns / 1ps

module project_16_tb;
    
  reg s, d;
  wire y0, y1;
  
  two_bit_splitter splitter(
    .s(s),
    .d(d),
    .y0(y0),
    .y1(y1)
  );
  
  initial
  begin
    s = 0; d = 0; #100
    s = 0; d = 1; #100
    s = 1; d = 0; #100
    s = 1; d = 1; #100
    $finish;
  end
endmodule
```

![two_bit_splitter](/Users/sudo/Desktop/Courses/summer_hardware/code/1_7_splitter/two_bit_splitter.png)

![GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/1_7_splitter/GUI.png)

<div style="page-break-after: always;"></div>

## Part II

### 1 to 4 Adder

#### 1 to 4 BCD Adder

> adder1_4_bcd.v

```verilog
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
```

> adder1_4_bcd_tb.v

```verilog
`timescale 1ns / 1ps

module adder1_4_bcd_tb;
    
  reg [3:0] a, b;
  reg cin;
  wire [3:0] s;
  wire cout;
  
  adder1_4_bcd_wrapper adder(
    .a_0(a[0]),
    .a_1(a[1]),
    .a_2(a[2]),
    .a_3(a[3]),
    .b_0(b[0]),
    .b_1(b[1]),
    .b_2(b[2]),
    .b_3(b[3]),
    .cin_0(cin),
    .sum_0(s[0]),
    .sum_1(s[1]),
    .sum_2(s[2]),
    .sum_3(s[3]),
    .cout_0(cout)
  );
  
  initial
  begin
    a = 0;  b = 0;  cin = 0;   #100;
    a = 6;  b = 9;  cin = 0;   #100;
    a = 3;  b = 3;  cin = 1;   #100;
    a = 4;  b = 5;  cin = 0;   #100;
    a = 8;  b = 2;  cin = 0;   #100;
    a = 9;  b = 9;  cin = 1;   #100;
    a = 8;  b = 1;  cin = 0;   #100;
    a = 6;  b = 2;  cin = 0;   #100;
    a = 9;  b = 1;  cin = 1;   #100;
    a = 7;  b = 0;  cin = 0;   #100;
  end
endmodule
```

![adder1_4_bcd](/Users/sudo/Desktop/Courses/summer_hardware/code/2_1_adder1_4/adder1_4_bcd.png)

![adder1_4_bcd_GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/2_1_adder1_4/adder1_4_bcd_GUI.png)

#### 1 to 4 Binary Adder

> adder1_4_bin.v

```verilog
//Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
//Date        : Tue Jul  5 17:06:45 2022
//Host        : DESKTOP-D18RA48 running 64-bit major release  (build 9200)
//Command     : generate_target adder1_4_bin.bd
//Design      : adder1_4_bin
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "adder1_4_bin,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=adder1_4_bin,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=4,numReposBlks=4,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}" *) (* HW_HANDOFF = "adder1_4_bin.hwdef" *) 
module adder1_4_bin
   (a_0,
    a_1,
    a_2,
    a_3,
    b_0,
    b_1,
    b_2,
    b_3,
    c_0,
    carry_0,
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
  input c_0;
  output carry_0;
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
  wire binary_adder_0_carry;
  wire binary_adder_0_sum;
  wire binary_adder_1_carry;
  wire binary_adder_1_sum;
  wire binary_adder_2_carry;
  wire binary_adder_2_sum;
  wire binary_adder_3_carry;
  wire binary_adder_3_sum;
  wire c_0_1;

  assign a_0_1 = a_0;
  assign a_1_1 = a_1;
  assign a_2_1 = a_2;
  assign a_3_1 = a_3;
  assign b_0_1 = b_0;
  assign b_1_1 = b_1;
  assign b_2_1 = b_2;
  assign b_3_1 = b_3;
  assign c_0_1 = c_0;
  assign carry_0 = binary_adder_3_carry;
  assign sum_0 = binary_adder_0_sum;
  assign sum_1 = binary_adder_1_sum;
  assign sum_2 = binary_adder_2_sum;
  assign sum_3 = binary_adder_3_sum;
  adder1_4_bin_binary_adder_0_0 binary_adder_0
       (.a(a_0_1),
        .b(b_0_1),
        .c(c_0_1),
        .carry(binary_adder_0_carry),
        .sum(binary_adder_0_sum));
  adder1_4_bin_binary_adder_0_1 binary_adder_1
       (.a(a_1_1),
        .b(b_1_1),
        .c(binary_adder_0_carry),
        .carry(binary_adder_1_carry),
        .sum(binary_adder_1_sum));
  adder1_4_bin_binary_adder_1_0 binary_adder_2
       (.a(a_2_1),
        .b(b_2_1),
        .c(binary_adder_1_carry),
        .carry(binary_adder_2_carry),
        .sum(binary_adder_2_sum));
  adder1_4_bin_binary_adder_2_0 binary_adder_3
       (.a(a_3_1),
        .b(b_3_1),
        .c(binary_adder_2_carry),
        .carry(binary_adder_3_carry),
        .sum(binary_adder_3_sum));
endmodule
```

> adder1_4_bin_tb.v

```verilog
`timescale 1ns / 1ps

module adder1_4_bin_tb;

  reg [3:0] a, b;
  reg c;
  wire [3:0] s;
  wire co;
  
  adder1_4_bin_wrapper adder(
    .a_0(a[0]),
    .a_1(a[1]),
    .a_2(a[2]),
    .a_3(a[3]),
    .b_0(b[0]),
    .b_1(b[1]),
    .b_2(b[2]),
    .b_3(b[3]),
    .c_0(c),
    .sum_0(s[0]),
    .sum_1(s[1]),
    .sum_2(s[2]),
    .sum_3(s[3]),
    .carry_0(co)
  );
  
  initial
  begin
    {a, b, c} = 9'b0;
    #1000 $finish;
  end
  
  always
  begin
    #10
    {a, b, c} = {a, b, c} + 1'b1;
  end
endmodule
```

![adder1_4_bin](/Users/sudo/Desktop/Courses/summer_hardware/code/2_1_adder1_4/adder1_4_bin.png)

![adder1_4_bin_GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/2_1_adder1_4/adder1_4_bin_GUI.png)

### 1 to 4 Full Adder

> full_adder1_4.v

```verilog
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
```

> full_adder1_4_tb.v

```verilog
`timescale 1ns / 1ps

module full_adder1_4_tb;

  reg [3:0] in1, in2;
  reg cin;
  wire [3:0] s;
  wire cout;
  
  reg [2:0] counter = 3'd0;
  
  full_adder1_4_wrapper adder(
    .in1_0(in1[0]),
    .in1_1(in1[1]),
    .in1_2(in1[2]),
    .in1_3(in1[3]),
    .in2_0(in2[0]),
    .in2_1(in2[1]),
    .in2_2(in2[2]),
    .in2_3(in2[3]),
    .cin_0(cin),
    .sum_0(s[0]),
    .sum_1(s[1]),
    .sum_2(s[2]),
    .sum_3(s[3]),
    .cout_0(cout)
  );
  
  initial
  begin
    in1 = 4'b0;
    in2 = 4'b0;
    cin = 1'b0;
    #100;
    
    for (counter = 0; counter < 8; counter = counter + 1'b1) begin
      {in1, in2, cin} = {in1, in2, cin} + 1'b1;
    #20;
    end
  end
endmodule
```

![full_adder1_4](/Users/sudo/Desktop/Courses/summer_hardware/code/2_2_full_adder/full_adder1_4.png)

![GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/2_2_full_adder/GUI.png)

### 2 to 4 MUX

> MUX2_4.v

```verilog
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
```

> MUX2_4_tb.v

```verilog
`timescale 1ns / 1ps

module MUX2_4_tb;

  reg [3:0] a;
  reg [1:0] s;
  wire out;
  
  MUX2_4_wrapper MUX(
    .D0_0(a[0]),
    .D0_1(a[1]),
    .D1_0(a[2]),
    .D1_1(a[3]),
    .S_0(s[0]),
    .S_1(s[1]),
    .Y_0(out)
  );
  
  initial
  begin
    a = 4'b1010;
    s = 2'b00; #100
    s = 2'b01; #100
    s = 2'b10; #100
    s = 2'b11; #100
    $stop;
  end
endmodule
```

![MUX2_4](/Users/sudo/Desktop/Courses/summer_hardware/code/2_3_mux/MUX2_4.png)

![GUI](/Users/sudo/Desktop/Courses/summer_hardware/code/2_3_mux/GUI.png)

### 1 to 4 Comparator

> comparator1_4.v

```verilog
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
```

> comparator1_4_tb.v

```verilog
`timescale 1ns / 1ps

module comparator1_4_tb;

  reg [4:0] a, b;
  wire greater, equal, less;
  
  initial
  begin
    {a, b} = 8'd0;
    #(16 * 16) $finish;
  end
  
  always
  begin
    #10
    {a, b} = {a, b} + 1;
  end
  
  comparator1_4 comparator(
    .a(a),
    .b(b),
    .greater(greater),
    .equal(equal),
    .less(less)
  );
endmodule
```

![comparator1_4](/Users/sudo/Desktop/Courses/summer_hardware/code/2_4_comparator/comparator1_4.png)

### 2 to 4 De-MUX

> splitter2_4.v

```verilog
`timescale 1ns / 1ps

module splitter2_4(in, out, sel);

  input in;
  input [1:0] sel;
  output [3:0] out;
  
  wire [3:0] dd;
  
  two_bit_splitter_0 u0 (
    .d(in),
    .s(sel[0]),
    .y0(dd[0]),
    .y1(dd[1])
  );
  
  two_bit_splitter_0 u1 (
    .d(in),
    .s(sel[1]),
    .y0(dd[2]),
    .y1(dd[3])
  );
  
  assign out = dd;
endmodule
```

> splitter2_4_tb.v

```verilog
`timescale 1ns / 1ps

module splitter2_4_tb;

    reg in;
    reg [1:0] sel;
    wire [3:0] out;
    
    splitter2_4 demux(
      .in(in),
      .sel(sel),
      .out(out)
    );
    
    initial
    begin
      {in, sel} = 3'd0;
      #100 $finish;
    end
    
    always
    begin
      #10
      {in, sel} = {in, sel} + 1'b1;
    end
endmodule
```

![splitter2_4](/Users/sudo/Desktop/Courses/summer_hardware/code/2_5_splitter/splitter2_4.png)

<div style="page-break-after: always;"></div>

## Part III

### Counter

> counter.v

```verilog
`timescale 1ns / 1ps

module counter(
  input clk, rst,
  output reg [7:0] Q
);
  always @(posedge clk or negedge rst)
  begin
    if(!rst)
      Q <= 0;
    else
      begin
        if(Q <= 99)
          Q <= Q+1;
        else
          Q <= 0;
      end
  end
endmodule
```

> counter_tb.v

```verilog
`timescale 1ns / 1ps

module counter_tb;

  reg clk, rst;
  wire [7:0] Q;
  counter counter_tb(
    .clk(clk),
    .rst(rst),
    .Q(Q)
  );
  initial
  begin
    clk = 0;
    rst = 0;
    #10 rst = 1;
    forever #10 clk = ~clk;
  end
endmodule
```

![counter](/Users/sudo/Desktop/Courses/summer_hardware/code/3_1_counter/counter.png)

### Seven-segment decoder

> seven_seg.v

```verilog
`timescale 1ns / 1ps

module seven_seg (
  bcd,
  seg
);
     
  // Declare inputs,outputs and internal variables.
  input [3:0] bcd;
  output [6:0] seg;
  reg [6:0] seg;

  // always block for converting bcd digit into 7 segment format
    always @(bcd)
    begin
      case (bcd)
        0 : seg = 7'b0000001;
        1 : seg = 7'b1001111;
        2 : seg = 7'b0010010;
        3 : seg = 7'b0000110;
        4 : seg = 7'b1001100;
        5 : seg = 7'b0100100;
        6 : seg = 7'b0100000;
        7 : seg = 7'b0001111;
        8 : seg = 7'b0000000;
        9 : seg = 7'b0000100;
        // not a decimal number
        default : seg = 7'b1111111; 
      endcase
    end
endmodule
```

> seven_seg_tb.v

```verilog
`timescale 1ns / 1ps

module seven_seg_tb;
    reg [3:0] bcd;
    wire [6:0] seg;
    integer i;

    seven_seg seg7 (
      .bcd(bcd), 
      .seg(seg)
    );

    initial
    begin
      for(i = 0; i < 16; i = i + 1)
      begin
        bcd = i;
        #50;
      end 
    end
endmodule
```

![seven_seg](/Users/sudo/Desktop/Courses/summer_hardware/code/3_2_seven_seg/seven_seg.png)

### ALU

> ALU.v

```verilog
module ALU(en, clk, opcode, x, y, z);

	parameter n = 8;
	
	input en, clk;
	input [2:0] opcode;
	input signed [n - 1 : 0] x, y;
	output signed [n : 0] z;
	
	reg signed [n : 0] z;
	
	parameter ADD = 3'b000, SUB = 3'b001, COMPARE = 3'b010, AND = 3'b011, OR =3'b100, NOT = 3'b101;
	
	always@(*)
	begin
		if(en)
		begin
			case(opcode)
				ADD: z <= x + y;
				SUB: z <= x - y;
				AND: z <= x & y;
				OR : z <= x | y;
				NOT : z <= ~x;
				COMPARE: z <= (x > y) ? 1 : ((x == y) ? 0 : 2);
				default: z <= 0;
			endcase
		end
	end
endmodule
```

> ALU_tb.v

```verilog
`timescale 1ns / 1ps

module ALU_tb;

  reg en, clk;
  reg [2:0] opcode;
  reg [7:0] x, y;
  wire [8:0] z;

  ALU testbench(
    .en(en),
    .clk(clk),
    .opcode(opcode),
    .x(x),
    .y(y),
    .z(z)
  );

  initial
  begin
    en = 1;
    clk = 0;
    opcode = 3'b000;
    x = 8'b00110011;
    y = 8'b10101010;
  end
  always #50 opcode[0] = ~opcode[0];
  always #50 opcode[1] = ~opcode[1];
  always #50 opcode[2] = ~opcode[2];
endmodule
```

![ALU](/Users/sudo/Desktop/Courses/summer_hardware/code/3_3_ALU/ALU.png)

### Grey

> grey.v

```verilog
`timescale 1ns / 1ps

module grey(
  input [7:0] bit,
  output [7:0] grey
);
    
  assign grey = (bit >> 1) ^ bit;
endmodule
```

> grey_tb.v

```verilog
`timescale 1ns / 1ps

module grey_tb;

  reg [7:0] bit;
  wire [7:0] grey;
  grey testbench(
    .bit(bit),
    .grey(grey)
  );

  initial
  begin
    bit = 8'b01100100; 
  end

  always #100 bit[0] = ~bit[0];
  always #100 bit[1] = ~bit[1];
  always #100 bit[2] = ~bit[2];
  always #100 bit[3] = ~bit[3];
  always #100 bit[4] = ~bit[4];
  always #100 bit[5] = ~bit[5];
  always #100 bit[6] = ~bit[6];
  always #100 bit[7] = ~bit[7];
endmodule
```

![grey](/Users/sudo/Desktop/Courses/summer_hardware/code/3_4_grey/grey.png)