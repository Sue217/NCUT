/*
【问题描述】编一程序，对于给定的一个百分制成绩，输出相应的五分值成绩。设90分以上为'A'，80-89分为'B，70－79分为'C'，60-69分为'D，,60分以下为'E'(用switch语句实现)。若输入的百分制成绩不在0-100之内，则输出error。

【输入形式】输入一行，包括一个百分制成绩，范围在0-100。

【输出形式】输出一行，给出这个百分制成绩相应的五分值成绩。

【样例输入】100

【样例输出】A

*/
#include<stdio.h>
int main(){
    int score;
    scanf("%d",&score);
    if(score>=0 && score<=100){
        switch(score / 10){
            case 10:
            case 9:printf("A\n");break;
            case 8:printf("B\n");break;
            case 7:printf("C\n");break;
            case 6:printf("D\n");break;
            default:printf("E\n");
        }
    }
    else printf("error\n");
    return 0;
}