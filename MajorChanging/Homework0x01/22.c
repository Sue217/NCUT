/*
【问题描述】写一个判断素数的函数，在主函数输入一个整数，输出是否是素数。

【输入形式】输入一行，包括1个整数。

【输出形式】输出一行，若是小于等于1的整数，刚输出error；若是素数，则输出YES，若不是素数输出NO。

【样例输入】11

【样例输出】YES
*/
#include<stdio.h>
int isPrime(int a){
    int i,j;
    for(i=2;i<a;i++){
        if(a % i == 0){
            j = 0;
            break;
        }
    }
    if(i >= a)j = 1;
    return j;
}
int main(){
    int num;
    scanf("%d",&num);
    if(num <= 1)printf("error\n");
    else{
        if(isPrime(num) == 1)printf("YES\n");
        if(isPrime(num) == 0)printf("NO\n");
    }
    return 0;
}