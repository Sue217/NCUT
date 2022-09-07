//写一个解一元二次方程的函数，主函数通过输入方程的系数a,b,c输出方程的根
#include<stdio.h>
#include<math.h>

double dert(int a,int b,int c)
{
    return b * b - 4 * a * c;
    
}

int main()
{
    int a, b, c, x1, x2;
    printf("请输入方程的系数a,b,c：");
    scanf_s("%d%d%d",&a,&b,&c);
    if (dert(a,b,c) < 0)
    {
        printf("此方程无实根");
    }
    if (dert(a, b, c) == 0)
    {
        printf("此方程有且仅有1个实根为：%f", (-b + sqrt(dert(a, b, c))) / 2 * a);
    }
    if (dert(a, b, c) > 0)
    {
        printf("此方程有两个不等实根，分别为：%lf和%lf", (-b - sqrt(dert(a, b, c))) / 2 * a, (-b + sqrt(dert(a, b, c))) / 2 * a);
    }
    return 0;
}

