#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x,y,z,s; 
	system("CLS");
	printf("input x,y,z\n");
	scanf("%d%d%d",&x,&y,&z);
	if(x>y)
	{
		s=x;
		x=y;
		y=s;
	}
	if(x>z)
	{
		s=x;
		x=z;
		z=s;
	}
	if(y>z)
	{
		s=y;
		y=z;
		z=s;
	}
	printf("the result from small to big is:%d%d%d",x,y,z);
}
