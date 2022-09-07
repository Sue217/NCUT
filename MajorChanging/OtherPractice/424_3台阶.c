//假设共M级台阶，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
#include<stdio.h>
int main(){
    int M,N,i,j,k,t,a,b,A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&M);
        a=1;b=1;
        for(j=1;j<M;j++){
            t = a + b;
            a = b;
            b = t;
        }
        A[i] = a;
    }
    for(i=0;i<N;i++)
        printf("%d\n",A[i]);
    return 0;
}