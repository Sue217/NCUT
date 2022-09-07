//五组得分去最高最低取平均

#include <iostream>
#include<stdio.h>
int main()
{
	float a[5], max, min, sum = 0, avg;
	int i, j;
	printf("输入5组总分：");
	for (i = 0;i < 5;i++)
		scanf_s("%f", &a[i]);
	max = a[0];
	min = a[0];
	for (i = 1;i < 5;i++)
		if (a[i] > max)
			max = a[i];
	for (j = 1;j < 5;j++)
		if (a[j] < min)
			min = a[j];
	for (i = 0;i < 5;i++)
		sum += a[i];
	avg = (sum - max - min) / 3;
	printf("平均分为%.3f", avg);
}

