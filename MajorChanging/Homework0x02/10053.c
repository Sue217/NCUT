/*
【问题描述】对输入的两个十六进制数(两个字符串)，将其转换成十进制后再求和。要求十六进制到十进制的转换功能由函数完成。
例如：输入3a1转换为十进制后为929，80转换为十进制后为128，所以和为1057。
【输入形式】输入包括两行，每行为一个十六进制数。注意：本题中的十六进制数中的英文字符以小写字母表示。
【输出形式】输出包括一行，为两数之和的十进制表示。
【样例输入】
    3a1
    80
【样例输出】
    1057
【样例说明】16进制数3a1和80转换为10进制数之后的和为1057(输出该数时后面不加换行符)。*/
#include<stdio.h>
#include<string.h>
int Reserve(char * str,int n){
    int i,ten = 0;
    for(i=0;i<n;i++){
        if(str[i]>='0' && str[i]<='9')ten = 16 * ten + (str[i] - '0');
        else if(str[i]>='a' && str[i]<='z')ten = 16 * ten + (str[i] - 'a') + 10;
    }
    return ten;
}
int main(){
    char num_1[1000] = {0};
    char num_2[1000] = {0};
    int m,n;
    gets(num_1);
    gets(num_2);
    m = strlen(num_1);
    n = strlen(num_2);
    printf("%d",Reserve(num_1,m) + Reserve(num_2,n));
    return 0;
}