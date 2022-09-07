//圆的面积函数
#include<stdio.h>
//全局变量将以下部分提前：
//float PI=3.14;
//S=PI*r*r;
//局部变量如下：
float f(float r)
{
    float PI;
    PI = 3.14;
    return PI * r * r;
}
int main()
{
    float r;
    printf("输入圆的半径：");
    scanf_s("%f", &r);
    float S;
    S = f(r);
    printf("圆的面积为：%f", S);
}

