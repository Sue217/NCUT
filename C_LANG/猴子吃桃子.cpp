//猴子第一天摘下N个桃子，当时吃了一半，还不过瘾，就有多吃了一个
//第二天又吃了剩下的一半，又多吃一个
//以后每天都吃前一天剩下的一半零一个
//到第10天想吃的时候就剩一个桃子了
//问第一天共摘下多少个桃子?并反向打印每天所剩桃子数

#include<stdio.h>

int getPeachNumber(int n)
{
	int num;
	if (n == 10)
	{
		return 1;
	}
	else
	{
		num = (getPeachNumber(n + 1) + 1) * 2;
		printf("第%d天所剩桃子数%d个\n", n, num);
	}
	return num;
}
int main()
{
	int num = getPeachNumber(1);
	printf("猴子第一天摘了：%d个桃子\n", num);
	return 0;
}
