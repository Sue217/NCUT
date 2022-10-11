//求一个四位整数的倒置结果
#include<stdio.h>
int main()
{
    int a, b = 0;
    printf("输入一个四位正整数：");
    scanf("%d", &a);
    if (a >= 1000 && a <= 9999)
    {
        do
        {
            b = b * 10 + a % 10;
            a = a / 10;
        } while (a != 0);
        printf("倒置的数为：%d", b);
    }
    else 
        printf("输入的数不符合要求，请输入四位正整数！");

}