/*
【问题描述】对于给定一个不多于5位的正整数，请按以下要求输出结果：

①求它是几位数；②分别打印出每一位数字；③按逆序打印出各位数字。例如原数为300，应输出003。

【输入形式】输入一行，一个不多于5位的正整数。

【输出形式】输出三行:

第一行输出是几位数

第二行正序输出每一位数字，各个数字间以空格分隔

第三行逆序输出每一位数字，各个数字间以空格分隔

【样例输入】12345

【样例输出】

5

1 2 3 4 5

5 4 3 2 1
*/
#include<stdio.h>
#include<string.h>
int main(){
    char str[5];
    int i,j;
    scanf("%s",str);
    printf("%lu\n",strlen(str));
    for(i=0;i<strlen(str);i++)printf("%c ",str[i]);
    printf("\n");
    for(j=strlen(str)-1;j>=0;j--)printf("%c ",str[j]);
    printf("\n");
    return 0;
}
/*
for(i=0,j=strlen(str)-1;i<strlen(str);i++,j--){
    c = str[i];
    str[i] = str[j];
    str[j] = c;
}//reverse
*/