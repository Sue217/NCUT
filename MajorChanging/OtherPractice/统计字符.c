//输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数
#include<stdio.h>
int main(){
    int num1=0,num2=0,num3=0,num4=0,i,j;
    char str[201];
    for(i=0;(str[i] = getchar())!='\n';i++){
        if(str[i]>='A' && str[i]<='z')num1++;
        else if(str[i]>='0' && str[i]<='9')num2++;
        else if(str[i] == ' ')num3++;
        else num4++;
    }
    printf("%d %d %d %d\n",num1,num2,num3,num4);
    return 0;
}
//In:aklsjflj123 sadf918u324 asdf91u32oasdf/.';123
//Out:23 16 2 4