/*问题描述

定义一个结构体变量（包括年、月、日）。输入某年某月某日，计算该日在本年中是第几天，注意闰年问题。

输入形式

输入一行，包括三个正整数，表示某年某月某日。

输出形式

输出一行，输出这一天是这一年的第几天。

样例输入

2013 3 5

样例输出

64
*/
#include<stdio.h>
struct Date{
    int year;
    int month;
    int day;
};
int days(struct Date date){
    int num = 0,Feb;
    if((date.year%4==0 && date.year%100!=0) || (date.year%400==0))Feb = 29;
    else Feb = 28;
    switch(date.month){
        case 1:num = 0;break;
        case 2:num = 31;break;
        case 3:num = 31+Feb;break;
        case 4:num = 31+31+Feb;break;
        case 5:num = 31+31+30+Feb;break;
        case 6:num = 31+31+30+31+Feb;break;
        case 7:num = 31+31+30+31+30+Feb;break;
        case 8:num = 31+31+30+31+30+31+Feb;break;
        case 9:num = 31+31+30+31+30+31+31+Feb;break;
        case 10:num = 31+31+30+31+30+31+31+30+Feb;break;
        case 11:num = 31+31+30+31+30+31+31+30+31+Feb;break;
        case 12:num = 31+31+30+31+30+31+31+30+31+30+Feb;break;
    }
    return num + date.day;
}
int main(){
    struct Date Day;
    scanf("%d%d%d",&Day.year,&Day.month,&Day.day);
    printf("%d\n",days(Day));
    return 0;
}

/*
#include<stdio.h>
struct Date{
    int year;
    int month;
    int day;
};
int main(){
    struct Date date;
    int Feb,num = 0,year,month,day;
    scanf("%d%d%d",&year,&month,&day);
    date.year = year;
    date.month = month;
    date.day = day;
    if((date.year%4==0 && date.year%100!=0) || date.year%400==0)Feb = 29;
    else Feb = 28;
    switch (date.month){
        case 1:num = 0;break;
        case 2:num = 31;break;
        case 3:num = 31+Feb;break;
        case 4:num = 31+31+Feb;break;
        case 5:num = 31+31+30+Feb;break;
        case 6:num = 31+31+30+31+Feb;break;
        case 7:num = 31+31+30+31+30+Feb;break;
        case 8:num = 31+31+30+31+30+31+Feb;break;
        case 9:num = 31+31+30+31+30+31+31+Feb;break;
        case 10:num = 31+31+30+31+30+31+31+30+Feb;break;
        case 11:num = 31+31+30+31+30+31+31+30+31+Feb;break;
        case 12:num = 31+31+30+31+30+31+31+30+31+30+Feb;break;
    }
    num += date.day;
    printf("%d\n",num);
    return 0;
}
*/