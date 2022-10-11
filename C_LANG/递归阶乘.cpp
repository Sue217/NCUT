

#include <iostream>
int factorial(int n)
{
    int num;
    if(n==1)
    {
        return 1;
    }
    else {
        num = (factorial(n)) * (factorial(n - 1));
        printf("第%d的阶乘结果为%d", n, num);
    }
    return num;
}
int main()
{
    int n = factorial(5);
    printf("请输入一个整数进行阶乘：");
    scanf_s("%d", &n);
    return 0;
}

