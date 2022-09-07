
//输入任意10个整数，利用冒泡法，从大到小排序

#include <iostream>

int main()
{
    int a[10];
    int i, j, k;
    printf("Please input 10 integers:");
    for (i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for (j = 0;j < 9;j++)
    {
        for (i = 0;i < 9 - j;i++)
        {
            if (a[i] < a[i + 1])
            {
                k = a[i];
                a[i] = a[i + 1];
               a[i + 1]=k;
            }
        }
    }
    for (i = 0;i < 10;i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
