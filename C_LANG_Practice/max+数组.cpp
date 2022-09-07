#include<stdio.h>
#define max
int main()
{
	int max(int x,int y)
	{
		int z;
		z=x>y?x:y;
		return (z);
	}
	int a[4];
	int i;
	printf("input 4 int numbers:");
	for (i=0;i<3,i++)
	scanf("%d",&a[i]);
	if (a[i]>a[i+1])
	max=a[i];
	printf("%d",a[i]);
	return 0;
}
