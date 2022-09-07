/*
问题描述

有n（n不大于20）个整数存放在一个数组中，请调用函数count( )，求出数组中的所有元素最大值、最小值、平均值（float数据类型，保留小数点两位）及各元素之和。（各个数之间以空格分隔）。

函数count( )声明如右：void count(int a[],int n,int *pmax,int *pmin,float *pave,int *psum) ;

输入形式

输入两行。

第一行输入整数n；

第二行输入n个数，各个数之间的空格分隔；

输出形式

输出一行，数组中的所有元素最大值、最小值、平均值及各元素之和。

样例输入

5
1 3 5 7 9

样例输出

9 1 5.00 25
*/
#include <stdio.h>
void count(int a[],int n,int * pmax,int * pmin,float * pave,int * psum){
    int i;
    *pmax = -1;
    *pmin = 1000000;
    *psum = 0;
    *pave = 0;
    for(i=0;i<n;i++){
        *psum += a[i];
        if(*pmax < a[i])*pmax = a[i];
        if(*pmin > a[i])*pmin = a[i];
    }
    *pave = (float)*psum / n;
}
int main(){
    int i,n,a[20],max = 0,min = 0,sum = 0;
    float avg = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    count(a,n,&max,&min,&avg,&sum);
    printf("%d %d %.2f %d\n",max,min,avg,sum);
    return 0;
}