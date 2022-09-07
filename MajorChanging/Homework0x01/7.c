/*
【问题描述】有3个整数a、b、c，由键盘输人，输出其中最大的数。

【输入形式】输入一行，包括3个整数。

【输出形式】输出一行，输出三个数中较大的数。

【样例输入】1 2 10

【样例输出】10
*/
#include<stdio.h>
int main(){
    int a,b,c,max = 0;
    scanf("%d%d%d",&a,&b,&c);
    max = (a > b)? a : b;//!
    max = (max > c)? max : c;//!
    printf("%d\n",max);
    return 0;
}