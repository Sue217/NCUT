#include<stdio.h>
int main(){
    int power(int x);
    long long sum = 0;
    int i;
    for(i=1;i<=10000;i++)
        sum += power(i);
    printf("%lld",sum);
    return 0;
}
int power(int x){
    return x * x;
}