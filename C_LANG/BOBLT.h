#pragma once
#include<stdio.h>
#include<math.h>//嵌套


//求x的n次方函数封装
double power(double x, int n)
{
	if (n == 0)//如果是if(n<=1)
	{
		return 1;//这里是return x;
	}
	else
	{
		return x * power(x, n - 1);
	}
}

#define PI 3.1415926
//圆的面积函数封装
double Circle_area(double r)
{
	return PI * r * r;
}

//球的表面积函数封装
double Ball_area(double r)
{
	return 4 * PI * power(r,2);
}

//球的体积函数封装
double Ball_volume(double r)
{
	return PI * power(r,3) * 4 / 3;
}
//质数判断函数封装
bool Prime_number(int num)
{
	bool b = true;
	for (int i = 2;i < num;i++)
	{
		if (num % i == 0)
		{
			b = false;
			break;
		}
	}
	return b;
}
//解一元二次方程函数封装
void Solve_equation(int a, int b, int c)
{
	if (a == 0)
	{
		printf("不是二次方程！\n");
		return;
	}
	double d = power(b, 2) - 4.0 * a * c;//dert=b^2-4ac
	if (d < 0)
	{
		printf("无实根\n");
		return;
	}

	double x1 = -b + sqrt(d) / (2.0 * a);
	double x2 = -b - sqrt(d) / (2.0 * a);
	printf("x1=%.2lf,x2=%.2lf", x1, x2);
}