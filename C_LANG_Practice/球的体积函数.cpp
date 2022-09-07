//球的体积函数
#include<stdio.h>
//全局变量将以下部分提前：
//float PI=3.14;
//V= 4/3 * PI * r * r * r;
//局部变量如下：
float f(float r)
{
    float PI;
    PI = 3.14;
    return 4/3 * PI * r * r * r;
}
int main()
{
    float r;
    printf("输入球的半径：");
    scanf_s("%f", &r);
    float V;
    V = f(r);
    printf("球的体积为：%f", V);
}

