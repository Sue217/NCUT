//复合语句中的变量
#include<stdio.h>
#define N 5
int main()
{
	int i;
	int a[N]={1,2,3,4,5};
	for (i=0;i<N/2;i++)
	{
		int temp;
		temp=a[i];
		a[i]=a[N-i-1];
		a[N-i-1]=temp;
	}
	for(i=0;i<N;i++)
	{
		printf("%d",a[i]);
	}
}
