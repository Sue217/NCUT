#include<stdio.h>
#include<math.h>
int Prime(int i){
    int t = 1,j;
    for(j=3;j<=sqrt(i);j+=2){
        if(i % j == 0){
            t = 0;
            break;
        }
    }
    return t;
}
int main(){
    int i,j,n,sum = 2;
    scanf("%d",&n);
    for(i=3;i<=n;i+=2){
        if(Prime(i) == 1)sum += i;
    }
    printf("%d\n",sum);
    return 0;
}