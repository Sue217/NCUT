
//结合指针，完成任意个整数的排序(学校利用new)

#include <iostream>
#include<stdio.h>
int main()
{
    int n=0,b,i,j;
    char ch;
    printf("请输入数组的长度：");
    scanf_s("%d", &n);
    int* a = new int[n];
    int k;
    printf("请输入指定长度的数组元素：");
    for (i = 0;i < n ;i++)
    {
        scanf_s("%d", &a[i]);
    }
    for ( j = 0;j < n-1;j++)
    {
        for (int i = 0;i < n -1 - j;i++)
        {
            if (a[i] < a[i+1])
            {
                k = a[i];
                a[i] = a[i + 1];
                a[i + 1] = k;
            }
        }
    }
    printf("输入的元素从大到小排序为：");
    for (i = 0;i < n ;i++)
    {
        printf("%4d",a[i]);
    }
    return 0;
}
