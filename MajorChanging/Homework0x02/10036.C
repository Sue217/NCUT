#include <stdio.h>
int main(){
    int i,sum = 0,num;
    for(i=100;i<1000;i++){
        num = i;
        while (num > 0){
            sum += (num % 10) * (num % 10) * (num % 10);
            num /= 10;
        }
        if(sum == i)printf("%d\n",i);
        sum = 0;
    }
    return 0;
}