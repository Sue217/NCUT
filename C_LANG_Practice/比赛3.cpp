#include<stdio.h>
int main()
{
    int i;
    scanf("%d",&i);
    int *a=new int[i];
	int max, min, sum = 0;
	float avg;
	int m, n;
	for (m = 0;m < i;m++)
		scanf("%f", &a[m]);
	max = a[0];
	min = a[0];
	for (m = 0;m < i;m++)
		if (a[m] > max)
			max = a[m];
	for (n = 0;n < i;n++)
		if (a[n] < min)
			min = a[n];
	for (m = 0;m < i;m++)
		sum += a[m];
	avg = (sum - max - min) / (i-2);
	printf("%.2f", avg);
}
