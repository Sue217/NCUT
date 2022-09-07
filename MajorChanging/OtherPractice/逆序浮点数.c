#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char str[15];
    int i,j;
    for(i=0;(str[i]=getchar())!='\n';i++);
    for(j=i-1;j>=0;j--)
        printf("%c",str[j]);
    printf("\n");
    return 0;
}