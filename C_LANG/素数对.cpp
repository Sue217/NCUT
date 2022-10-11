//用函数求两个相邻的素数(素数对)
#include<stdio.h>
int max(int x)
{
	int i;
	for(i=2;i<x;i++)
	if(x%i==0)
	return 0;
	return 1;
}
int main()
{
	int a,b;
	for(a=3;a<=100;a+=2)
	for(b=3;b<=100;b+=2)
	if(max(a)==1&&max(b)==1&&a<b&&(b-a)==2)
	printf("%d%d\n",a,b); 
}
