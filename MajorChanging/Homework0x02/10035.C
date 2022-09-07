/*
【问题描述】输入两个正整数m和n，求其最大公约数和最小公倍数。
【输入形式】一行，两个正整数，以逗号间隔开。
【输出形式】一行，第一个数为最大公约数，第二个为其最小公倍数，以逗号间隔开
【样例输入】35,49
【样例输出】7,245
*/
#include<stdio.h>
void Bn(int m,int n){
    int max = -1;
    while(max != 0){
        max = m % n;
        if(max == 0){
            printf("%d,",n);
            break;
        }
        else{
            m = n;
            n = max;
        }
    }
}
void Sn(int m,int n){
    int i,tmp;
    if(m > n){
        tmp = m;
        m = n;
        n = tmp;
    }
    for(i=n;i%m!=0 || i%n!=0;i++);
    printf("%d\n",i);
}
int main(){
    int num1,num2;
    scanf("%d,%d",&num1,&num2);
    Bn(num1,num2);
    Sn(num1,num2);
    return 0;
}