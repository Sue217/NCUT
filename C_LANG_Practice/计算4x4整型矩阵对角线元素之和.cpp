//计算4x4整型矩阵对角线元素之和
#include<stdio.h>
int main()
{
    int a[4][4], sum = 0;
    for (int i = 0;i < 4;i++)
    {
        printf("请输入第%d行：", i + 1);
        for (int j = 0;j < 4;j++)
        {
            
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0;i < 4;i++)
    {
        sum = sum + a[i][i];
    }
    printf("sum=%d\n", sum);
    return 0;
}