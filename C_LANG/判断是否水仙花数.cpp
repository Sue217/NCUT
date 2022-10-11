#include<stdio.h>
int main()
{
	int x,a,b,c;
	printf("输入一个正整数");
	scanf("%d",&x);
	a=x/100;
	b=(x/10)%10;
	c=x%10;
	if (a*a*a+b*b*b+c*c*c==x)
	printf("是");
	else printf("不是"); 
}
