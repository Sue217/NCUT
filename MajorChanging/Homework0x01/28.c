/*问题描述

有一字符串，包含n个字符。写一函数，用指针方法实现将此字符串中从第m个字符开始的全部字符复制成为另一个字符串，其中m小于n。

输入形式

输入两行，第一行是一个字符串，第二行是正整数m。

输出形式

输出一行，给出满足条件复制后的字符串。

样例输入

You are a student.

5

样例输出

are a student.
*/
//百题后感
#include <stdio.h>
#include <string.h>
char * str_cpy(char * str,int n){
    int i,j,len = strlen(str);
    char * p = str;
    for(i=0;i<n-1;i++)p++;
    for(i=n-1,j=0;i<len;j++,p++,i++)
        str[j] = *p;
    str[j] = '\0';
    return str;
}
int main(){
    int m;
    char str[100];
    gets(str);
    scanf("%d",&m);
    printf("%s\n",str_cpy(str,m));
    return 0;
}
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// char * str_cpy(char * str1,int m){
//     int n = strlen(str1);
//     char * p = str1 + m - 1;
//     char * str2 = (char *)malloc(m);
//     int i,j;
//     for(i=m-1,j=0;i<n;i++){
//         str2[j++] = *p;
//         p++;
//     }
//     str2[j] = '\0';
//     free(str2);
//     return str2;
// }
// int main(){
//     char str[100];
//     int i,m;
//     for(i=0;(str[i]=getchar())!='\n';i++);
//     if(str[i] == '\n')str[i] = '\0';
//     scanf("%d",&m);
//     printf("%s\n",str_cpy(str,m));
//     return 0;
// }