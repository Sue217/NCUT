// AB数题目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定n(n<=10000,k<=100)将从1到n之间所有数可分为两类：A类数可以被k整除，而B类数不能。请输出这两类数的平均数，精确到0.1
//数据保证两类数都不是0

#include <stdio.h>

int main()
{
    int n, k, i,c=0,d=0, A=0, B=0;
    double avg1, avg2;
    printf("please input two integer numbers:n,k.( make sure n<=10000,k<=100):");
    scanf_s("%d%d", &n, &k);
    if (n <= 10000 && k <= 100)
    {
        for (i = 1;i <= n;i++)
        {
            if (i % k == 0)
            {
                c++;
                A = A + i;
            }
            else {
                d++;
                B = B + i;
            }
        }
        avg1 = A / c;
        avg2 = B / d;
    }
    else {
        printf("error");
    }
    printf("avg1=%.1f  avg2=%.1f", avg1, avg2);
}
