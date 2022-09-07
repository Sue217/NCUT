/*问题描述

写一转换函数，实现十六进制数向十进制数的转换。主函数中输入一个十六进制数，输出相应的十进制数。转换功能是转换函数完成。

输入形式

输入一行，只包括一个十六进制数，输入的字母可大写也可小写，如A0与a0表示同样的数。

输出形式

输出一行，输出相应的十进制数。

样例输入

A0

样例输出

160

*/
#include<stdio.h>
#include<string.h>
int Transfer(char * str,int n){
    int i,ten = 0;
    for(i=0;i<n;i++){
        if(str[i]>='0' && str[i]<='9')ten = ten * 16 + (str[i] - '0');
        else if(str[i]>='A' && str[i]<='Z')ten = ten * 16 + (str[i] - 'A') + 10;
        else if(str[i]>='a' && str[i]<='z')ten = ten * 16 + (str[i] - 'a') + 10;
    }
    return ten;
}
int main(){
    char str[100];
    scanf("%s",str);
    printf("%d\n",Transfer(str,strlen(str)));
    return 0;
}