#include <stdio.h>
union  byte2any
{
	int n;
	float f;
	unsigned char byte[4];
};
int main()
{
	byte2any num;
	num.byte[0] = 0;
	num.byte[1] = 0;
	num.byte[2] = 0;
	num.byte[3] = 0;
	printf("%d, %f\n", num.n, num.f);
	printf("%d ,%d, %d, %d", num.byte[0], num.byte[1], num.byte[2], num.byte[3]);
	return 0;
}
