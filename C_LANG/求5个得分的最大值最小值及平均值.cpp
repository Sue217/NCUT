//求5个得分的最大值最小值及平均值
#include<stdio.h>
float max = 0, min = 0;
float average(float arr[], int n);
int main()
{
	float score[5] = { 90,80,65,95,70 };
	for (int i = 0;i < 5;i++)
	{
		float ave = average(score, 5);
		printf("max=%.2f,min=%.2f,ave=%.2f\n",max,min,ave);
	}
	return 0;
}
float average(float arr[], int n)
{
	static float sum = arr[0];
	float ave = 0;
	max = arr[0];
	min = arr[0];
	for (int i = 1;i < n;i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else if (arr[i] < min)
		{
			min = arr[i];
		}
		sum += arr[i];
	}
	ave = sum / n;
	return ave;
}