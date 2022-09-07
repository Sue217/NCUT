#include<stdio.h>
int main(){
    int i,j,n,a[n],min,tmp;
    for(i=0;i<n-1;i++)
        min = i;
        for(j=i+1;j<n;j++)
            if(a[j] < a[min])min = j;//string:if(strcmp(a[j],a[min]) < 0)
        if(min != i){
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
        printf("%d",a[i]);
}