//利用函数找素数
#include<stdio.h>
int f(int n)
{
	int i,j;
	for (i = 3;i <= n-2;i+=2)
	{
		for (j=2;j< n-2;j++)
		{
			if (j==i)
			{
				printf("%d   ",i);
			} 
		}
		
	}
	return i;
}
int main()
{
	printf("%d", f(100));
	return 0;
}
