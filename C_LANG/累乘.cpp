#include<stdio.h>
int main()
{
	int i,sum;
	i=2; 
	sum=1;
	while (i<=10)
	{
		sum=sum*i;
		i++; 
	}
	printf("sum=%5d\n",sum);
}
