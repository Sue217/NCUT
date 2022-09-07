/*问题描述

写一个函数，利用递归方法求给定整数n的阶乘（n不大于20）。在主函数输入一个整数n，输出该整数的阶乘。

输入形式

输入一行，只包括一个整数n（n不大于20）。

输出形式

输出一行，输出n的阶乘。

样例输入

10

样例输出

3628800

*/
#include<stdio.h>
long fac(int n){
    long res = 1;
    if(n > 0)res = n * fac(n-1);
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%ld\n",fac(n));
    return 0;
}