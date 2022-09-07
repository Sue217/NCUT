/*
问题描述

有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前n项之和。n的值由scanf输入。

输入形式

输入一行，包括n的值。

输出形式

输出一行，给出前n项之和，保留小数点后6位。

样例输入

2

样例输出

3.500000
*/
#include<stdio.h>
int main(){
    double sum = 0.0,tmp,a = 2.0,b = 1.0;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        sum += a / b;
        tmp = a;
        a += b;
        b = tmp;
    }
    printf("%lf\n",sum);
    return 0;
}