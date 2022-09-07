/*问题描述

编写一函数，由实参传来一个字符串（长度不大于30），统计此字符串中字母、数字、空格和其他字符的个数，在主函数中输入字符串以及输出上述的结果。

输入形式

输入一行，输入一字符串。

输出形式

输出一行，字符串中字母、数字、空格和其他字符的个数。各个数值之间以空格分隔。

样例输入

My class is computer_4.

样例输出

17 1 3 2
*/
#include<stdio.h>
int cha=0,num=0,spa=0,oth=0;
void strCheck(char * str){
    int i;
    for(i=0;str[i]!='\0';i++){
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))cha++;
        else if(str[i]>='0' && str[i]<='9')num++;
        else if(str[i]==' ')spa++;
        else oth++;
    }
}
int main(){
    char str[32];
    int i;
    for(i=0;(str[i]=getchar())!='\n';i++);
    if(str[i] == '\n')str[i] = '\0';
    strCheck(str);
    printf("%d %d %d %d\n",cha,num,spa,oth);
    return 0;
}