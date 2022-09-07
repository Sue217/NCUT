#include<stdio.h>
int main(){
    int i=0,num[1000],t;
    char plus;
    while(plus != '\n')scanf("%d%c",&num[i++],&plus);
    for(int p=0;p<i;p++){
        for(int q=i-1;q>p;q--){
            if(num[q] < num[q-1]){
                t = num[q];
                num[q] = num[q-1];
                num[q-1] = t;
            }
        }
    }
    for(int p=0;p<i-1;p++)printf("%d+",num[p]);
    printf("%d",num[i-1]);
    return 0;
}
/*
#include<stdio.h>
int main(){
    int i=0,num[1000],t;
    char plus;
    while(plus != '\n')scanf("%d%c",&num[i++],&plus);
    for(int p=0;p<i;p++){
        for(int q=i-1;q>p;q--){
            if(num[q] < num[q-1]){
                t = num[q];
                num[q] = num[q-1];
                num[q-1] = t;
            }
        }
    }
    for(int p=0;p<i-1;p++)printf("%d+",num[p]);
    printf("%d",num[i-1]);
    return 0;
}*/