#include<stdio.h>
int main(){
    int a[3],tmp;
    for(int i=0;i<3;i++)scanf("%d",&a[i]);
    for(int i=0;i<3;i++)
        for(int j=2;j>i;j--){
            if(a[j-1] > a[j]){
            tmp = a[j-1];
            a[j-1] = a[j];
            a[j] = tmp;
            }
        }
    for(int i=0;i<3;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}