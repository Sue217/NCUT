//指针案例
#include <iostream>

int main()
{
    //int i, j;                                               
    //int* pointer_1, * pointer_2;      //!初始化
    //pointer_1 = &i;                   //[存储类型] 数据类型*指针名=初始地址值
    //pointer_2 = &j;                   //!一个指针变量只能值相同类型的变量

    //int a;
    //int* pa = &a;
    // a = 10;
    // printf("a:%d\n*pa:%d\n&a:%d\npa:%d\n&pa:%d\n",a,*pa,&a,pa,&pa);

    int  n ;
    printf("input a number:");
    scanf_s("%d", &n);
    int* a = new int[n];
    for (int i = 0;i < n;i++)
    {
        a[i] = i * 10;

    }
    for (int i = 0;i < n;i++)
    {
        printf("%d\n", a[i]);
    }
    delete a;
    return 0;
}

