#include<stdio.h>
int main()
{
	float a=1000000.0f;
	float b=30.0f;
	float m=a/b;
	double c=1.0e6;
	double d=3.0e1;
	double n=c/d;
	printf("%f\n",m);
	printf("%f",n);
	return 0;
}
