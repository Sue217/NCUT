/*问题描述

输入三个整数，按由小到大的顺序输出。用指针方法实现。

输入形式

输入一行，只包括三个整数。

输出形式

输出一行，按小到大的顺序输出这三个整数，各个整数间以空格分隔。

样例输入

3 2 1

样例输出

1 2 3
*/
#include<stdio.h>
int main(){
    int a,b,c;
    int * ap = &a;
    int * bp = &b;
    int * cp = &c;
    scanf("%d%d%d",&a,&b,&c);
    if(*ap > *bp){
        *ap = *ap ^ *bp;
        *bp = *ap ^ *bp;
        *ap = *ap ^ *bp;
    }
    if(*ap > *cp){
        *ap = *ap ^ *cp;
        *cp = *ap ^ *cp;
        *ap = *ap ^ *cp;
    }
    if(*bp > *cp){
        *bp = *bp ^ *cp;
        *cp = *bp ^ *cp;
        *bp = *bp ^ *cp;
    }
    printf("%d %d %d\n",*ap,*bp,*cp);
    return 0;
}