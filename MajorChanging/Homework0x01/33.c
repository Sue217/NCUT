/*
问题描述

从键盘输入一个字符串，将其中的小写字母全部转换成大写字母，然后输出到一个磁盘文件"test.txt"中保存。输入的字符串以"！"结束。

输入形式

输入一行，只包括一个字符串，输入的字符串以"！"结束（!不保存到文件中）。

输出形式

输入的字符转换后保存到test.txt文件中。

样例输入

abc 123!

样例输出

ABC 123
*/
#include<stdio.h>
int main(){
    char ch[100];
    int i = 0,j;
    FILE * f_write = fopen("test.txt","w");
    if(f_write == NULL)return 0;
    while((ch[i]=getchar())!='!'){
        if(ch[i]>='a' && ch[i]<='z')ch[i] -= 32;
        i++;
    }
    for(j=0;j<i;j++)putc(ch[j],f_write);
    fclose(f_write);
    return 0;
}