/*
问题描述

求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个小于10的正整数。

例如2+22+222+2222+22222(此时共有5个数相加)，相加的数的个数n与a的值由scanf控制。

输入形式

输入一行，包括a和n（n表示几个数相加）。

输出形式

输出一行，输出和。

样例输入

2 5

样例输出

24690

*/
#include<stdio.h>
int main(){
    int a,n,s = 0,i,tmp;
    scanf("%d%d",&a,&n);
    tmp = a;
    for(i=0;i<n;i++){
        s += a;
        a = 10 * a + tmp;
    }
    printf("%d\n",s);
    return 0;
}