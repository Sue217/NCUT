/*
【问题描述】There are another kind of Fibonacci number:F(0)=7,F(1)=11,F(n)=F(n-1)+F(n-2) (n>=2).
【输入形式】Input an interger n.(n<1000000)
【输出形式】Print the word "yes" if 3 divide evenly into F(n).Print the word "no" if not.
【样例输入】5
【样例输出】no
【样例说明】if input 5,print the word"no".*/
#include<stdio.h>
int main(){
    int n,k,f[1000005];
    scanf("%d",&n);
    f[0] = 7 % 3;
    f[1] = 11 % 3;
    for(k=2;k<=n;k++){
        f[k] = (f[k-1] + f[k-2]) % 3;
    }
    if(n>=2 && f[n] == 0)printf("yes\n");
    else printf("no\n");
    return 0;
}