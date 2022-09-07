/*问题描述

完全数是这样一个整数，它加上100后是一个完全平方数，它加上268也是一个完全平方数。编程程序求出m，n之间所有完全数（包括m和n），其中n>m。

输入形式

输入一行，包括整数m和n。

输出形式

输出一行，输出m与n间的所有完全数，各数之间以空格分隔。若没有，则输出no。

样例输入

1 10000

样例输出

21 261 1581
*/
#include<stdio.h>
#include<math.h>
int main(){
    int m,n,i,flag = 0;
    double j,k;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++){
        j = (int)sqrt(i+100);
        k = (int)sqrt(i+268);
        if(i+100 == j*j && i+268 == k*k){
            printf("%d ",i);
            flag = 1;
        }
    }
    if(flag == 0)printf("no");
    printf("\n");
    return 0;
}