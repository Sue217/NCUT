//打印九九乘法表
#include<stdio.h>
int main()
{
    int sum;
    int i, j;
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            if (i <= j)
            {
                sum = i * j;
                printf("%d*%d=%2d  ", i, j, sum);
            }
        }
        printf("\n");
    }
    return 0;
}
