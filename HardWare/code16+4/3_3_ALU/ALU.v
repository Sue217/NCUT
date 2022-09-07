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
