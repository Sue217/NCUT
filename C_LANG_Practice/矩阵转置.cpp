
//求3*3矩阵A的转置矩阵
//矩阵A由键盘输入
//提示：用二重for循环实现，循环体内实现a[i][j]和a[j][i]的互换

#include<stdio.h>
int main()
{

    int a[3][3];
    int b[3][3], i,j;
    printf("input 9 integers to combine array a:\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
        {
            printf("input array a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);                                   
            b[j][i] = a[i][j];
        }
        
    }
    printf("\n");
    printf("array a的转置为:\n");
    for (i = 0;i < 3;i++)
    {
        for (j = 0;j < 3;j++)
            printf("%5d",b[i][j]);
        printf("\n");
    }
    return 0;
}
