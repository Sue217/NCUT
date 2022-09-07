#include <stdio.h>

void pyramid(int n);

int main()
{    
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}
void pyramid(int n){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(k=n-i;k>0;k--)
            printf(" ");
        for(j=0;j<i;j++)
            printf("%d ",i);
            printf("\n");
        }       
}