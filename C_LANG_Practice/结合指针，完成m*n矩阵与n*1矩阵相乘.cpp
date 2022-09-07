//结合指针，完成m*n矩阵与n*1矩阵相乘

#include <iostream>
#include <iostream>
#include<stdio.h>
int main()
{
    int m, n, i, j;
    int sum = 0;
    printf("请先输入m*n矩阵的维数m,n：");
    scanf_s("%d%d", &m, &n);
    int** a = new int* [m];
    for (int k = 0;k < m;k++)
    {
        a[k] = new int[n];
    }
    printf("现在请输入矩阵A：\n");
    for (i = 0;i < m;i++)
    {
        for (j = 0;j < n;j++)
        {
            printf("A[%d][%d]", i, j);
            scanf_s("%d", &a[i][j]);
        }
    }
    
    int* b = new int[n];
    printf("现在请输入矩阵B：\n");
    for (i = 0;i < n;i++)
    {
        
            printf("B[%d]", i);
            scanf_s("%d", &b[i]);
        
    }

    printf("乘积的结果为：\n");
    int* c = new int[n];
    for (i = 0;i < m;i++)
    {
            for (int g = 0;g < n;g++)
            {               
                    sum = sum + a[i][g] * b[g];
                

            }

            c[i] = sum;
        
    }
    for (i = 0;i < m;i++)
    {
            printf("%4d\n", c[i]);
        
    }
    return 0;
}

