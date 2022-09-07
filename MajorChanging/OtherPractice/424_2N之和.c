//输入一个数字N，输出N以内（包含N）的数字之和 （N不超过1000）
#include<stdio.h>
int main(){
    int i,N,sum = 0;
    scanf("%d",&N);
    for(i=0;i<=N;i++)
        sum += i;
    printf("%d\n",sum);
    return 0;
}