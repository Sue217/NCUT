/*
【问题描述】有一个函数：
    y=x     (x<1)
    y=2x-1  (1<=x<10)
    y=3x-11 (x>=10)
写一个程序，输入x值，计算y值。
【输入形式】一个整数x。
【输出形式】输出函数值y。
【样例输入】20
【样例输出】49
【样例说明】输入20时，输出结果为49。*/
#include<stdio.h>
int main(){
    int x,y;
    scanf("%d",&x);
    if(x < 1)y = x;
    else if(x>=1 && x<10)y = 2 * x - 1;
    else if(x >= 10)y = 3 * x - 11;
    printf("%d\n",y);
    return 0;
}