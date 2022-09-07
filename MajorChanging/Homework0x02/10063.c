/*
【问题描述】在国外，每月的13号和每周的星期5都是不吉利的。特别是当13号那天恰好是星期5时更不吉利
已知某年的一月一日是星期W，并且这一年一定不是闰年，求出这一年所有13号那天是星期5的月份
按从小到大的顺序输出月份数字(W=1..7)
【输入形式】输入有一行，即一月一日星期几(W)(1<=w<=7)
【输出形式】输出有一到多行，每行一个月份，表示该月的13日是星期五
【样例输入】7
【样例输出】1 10
【样例说明】1月1日是星期7的年，1月、10月都是不吉利日期
*/
#include<stdio.h>
int month(int i){
    int m = 0 ;
    switch(i){
        case 1:m = 31;break;
        case 2:m = 28;break;
        case 3:m = 31;break;
        case 4:m = 30;break;
        case 5:m = 31;break;
        case 6:m = 30;break;
        case 7:m = 31;break;
        case 8:m = 31;break;
        case 9:m = 30;break;
        case 10:m = 31;break;
        case 11:m = 30;break;
        case 12:m = 31;break;
        default:;
    }
    return m;
}
int main(){
    int w,i,j;
    scanf("%d",&w);
    for(i=1;i<=12;i++){
        for(j=1;j<=month(i);j++){
            if(j == 13 && w == 5){
                printf("%d\n",i);
            }
            if(w % 7 == 0)w = 0;
            w++;
        }
    }
    return 0;
}