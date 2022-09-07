/*
【问题描述】有一分数序列:
2/1,3/2,5/3,8/5,13/8,21/13........求出该序列前n项之和                                    
【输入形式】输入只有一行，该行包含一个正整数n(n<200).
【输出形式】序列前n项之和(保留两位小数)
【样例输入】2
【样例输出】3.50
*/
#include<stdio.h>
int main(){
    int n,i,tmp;
    float a = 2,b = 1,sum = 0.0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        sum += a / b;
        tmp = a + b;
        b = a;
        a = tmp;
    }
    printf("%.2f\n",sum);
    return 0;
}