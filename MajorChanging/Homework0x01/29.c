/*问题描述

输入一行文字，找出其中大写字母、小写字母、空格、数字以及其他字符各有多少。用指针方法实现。

输入形式

输入一行，输入一字符串（字符串的字符不多于80个）。

输出形式

输出一行，找出其中大写字母、小写字母、空格、数字以及其他字符各有多少个。各个数值之间以空格分隔。

样例输入

It is a dog. 2 or 3 years old?

样例输出

1 17 8 2 2
*/
#include<stdio.h>
#include<string.h>
int main(){
    char str[85];
    char * p = str;
    int bc=0,sc=0,spa=0,num=0,oth=0;
    gets(str);
    while(*p != '\0'){
        if(*p>='A' && *p<='Z')bc++;
        else if(*p>='a' && *p<='z')sc++;
        else if(*p==' ')spa++;
        else if(*p>='0' && *p<='9')num++;
        else oth++;
        p++;
    }
    printf("%d %d %d %d %d\n",bc,sc,spa,num,oth);
    return 0;
}