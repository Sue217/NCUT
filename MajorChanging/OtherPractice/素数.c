#include<stdio.h>
int main(){
    int i,j,m = 0;
    long long n;
    scanf("%lld",&n);
    for(i=2;i<n;i++){
        for(j=2;j<i;j++)
            if(i % j == 0)break;
        if(j >= i)m++;
    }
    printf("%d",m);
    return 0;
}