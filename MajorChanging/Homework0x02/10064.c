/*
【问题描述】判断一个由a-z 这26个字符组成的字符串中哪个字符出现的次数最多
【输入形式】第1行是测试数据的组数n,每组测试数据占1行，是一个由a-z这26个字符组成的字符串
每行数据不超过1000个字符且非空
【输出形式】输出n行，每行输出对应一个输入。一行输出包括出现次数最多的字符和该字符出现的次数
中间是一个空格。如果有多个字符出现的次数相同且最多，那么输出ASCII码最小的那一个字符
【样例输入】
2
abbccc
adfadffasdf
【样例输出】
c 3
f 4
*/
#include<stdio.h>
int main(){
    int n,i,j,k,ch[26],max;
    char a[50][1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",*(a+i));
    for(i=0;i<n;i++){
        for(k=0;k<26;k++)ch[k] = 0;
        for(j=0;a[i][j]!='\0';j++)ch[a[i][j] - 'a' + 0]++;
        for(k=0,max=0;k<26;k++){
            if(ch[max] < ch[k])max = k;
        }
        printf("%c %d\n",max + 'a',ch[max]);
    }
    return 0;
}