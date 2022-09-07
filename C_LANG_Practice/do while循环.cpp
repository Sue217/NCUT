//do while循环
#include<stdio.h>
int main()
{
    int b = 1;
    double a = 1, sum = 0;
    do
    {
        a = a * b;
        sum += a;
        b++;
    } while (b <= 20);
        printf("计算结果是：%f", sum);
}
