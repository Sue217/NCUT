/*问题描述

从键盘输入两个字符串a和b，要求不用库函数strcat把串b的前五个字符连接到串a中；如果b的长度小于5，则把b的所有元素都连接到a中。并输出连接后的字符串a。(字符串中可能含有空格）

输入形式

输入两行，两个字符串a和b，（两个字符串的长度小于80）。

输出形式

输出一行，输出字符串a。

样例输入

student

and I

样例输出

studentand I

*/
#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[]){
    char a[160],b[80];
    int i,la,lb;
    gets(a);
    gets(b);
    la = strlen(a);
    lb = strlen(b);
    if(lb < 5){
        for(i=0;i<lb;i++)
            a[la+i] = b[i];
        for(i=0;i<la+lb;i++)
            printf("%c",a[i]);
        printf("\n");
    }
    else{
        for(i=0;i<5;i++)
            a[la+i] = b[i];
        for(i=0;i<la+5;i++)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}