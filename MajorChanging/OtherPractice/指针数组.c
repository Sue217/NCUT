/*
问题描述

编一程序，输入月份号，输出该月的英文月名。例如：输入3，则输出March,要求用指针数组处理。（英文月名的第一个字母大写）。

输入形式

输入一行，输入一个整数，范围在1到12之间，表示月份名。

输出形式

输出一行，给出该月的英文月名。若输入的整数不在1到12之间，则输出error。

样例输入

3

样例输出

March
*/
#include <stdio.h>
int main(){
    int n;
    char * month[12] = {"January","February","March","April","May","June","July","August",
                        "September","October","November","December"};
    scanf("%d",&n);
    if(n>12 || n<1)printf("error\n");
    else printf("%s\n",month[n-1]);
    return 0;
}