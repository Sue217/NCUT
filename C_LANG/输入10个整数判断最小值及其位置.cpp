//输入10个整数判断最小值及其位置
#include<stdio.h>
int main()
{
	int num[10] = {0};
	int i = 0;
	int min = 0;
	printf("please input 10 integrates");
	for (i = 0; i < sizeof(num)/ sizeof(num[0]); i++)
	{
	scanf("%d",&num[i]);
	}
	min = num[0];
	for (i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
	if (min > num[i])
	{
	min = num[i];
	break;
	}

	} 
	printf("the minimum number is:%d\nit is the %d", min,i+1);
	return 0;
}

