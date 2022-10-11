#include<stdio.h>
int main()
{
	int x;
	printf("input");
	scanf("%d",&x);
	if (x>=0&&x<60)
	printf("U");
	else if (x>=60&&x<70)
	printf("D");
	else if (x>=70&&x<80)
	printf("C");
	else if (x>=80&&x<90)
	printf("B");
	else if (x>=90&&x<=100)
	printf("A"); 
}

