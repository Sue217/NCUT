/*
问题描述

求1+2!+3!+...+n!的和。n的值由scanf输入。

输入形式

输入一行，包括n的值。

输出形式

输出一行，给出1到n的阶乘的和。

样例输入

3

样例输出

9
*/
#include<stdio.h>
int fac(int a){
    int n = 1;
    while(a > 0)n *= (a--);
    return n;
}
int main(){
    int n,i,j,sum = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)sum += fac(i);
    printf("%d\n",sum);
    return 0;
}