
#include <iostream>
#include<stdio.h>
double power(double x, int n)//函数返回值类型要表明int||double||void......形参类型要依次说明
{
    double p = 1;
    for (int i = 0;i < n;i++)
    {
        p *= x;
    }
    return p;
}
int main()
{
    printf("%.2lf\n", power(5, 3));
    double x = 10;
    int n = 5;
    double y = power(x, n);//与上述定义函数的x,n无直接关系
    printf("%.2lf", y);
    return 0;
}

