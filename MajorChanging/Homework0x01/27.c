/*问题描述

有n个整数，使前面各数顺序向后移m个位置，最后m个数变成前面m个数

写一函数：实现以上功能，在主函数中输入n个数和输出调整后的n个数。用指针方法实现。

输入形式

输入两行，第一行输入n和m，第二行输入n个整数。

输出形式

输出一行，输出调整后的n个数。

样例输入

6 2

1 2 3 4 5 6

样例输出

5 6 1 2 3 4

*/
#include<stdio.h>
void move(int a[],int n,int m){
    int * p = a;
    int i,b[100];
    for(i=0;i<n;i++,p++)b[i] = *p;
    for(i=0,p=&b[n-m];p<&b[n];i++,p++)a[i] = *p;
    for(i=m,p=b;p<&b[n-m];i++,p++)a[i] = *p;
}
int main(){
    int m,n,num[100],res[100],i;
    int * p = num;
    int * q = res;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",p++);
    p = num;
    move(num,n,m);
    q = num;
    for(i=0;i<n;i++)printf("%d ",*q++);
    printf("\n");
    return 0;
}