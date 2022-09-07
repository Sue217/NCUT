/*问题描述

求一个n*n矩阵对角线元素之和（n<=10）。

输入形式

输入n+1行，第一行输入正整数n。

后面的n行输入对应的n*n矩阵对角线各个元素，各个元素的值为整数。

输出形式

输出一行，给出一个正整数，输出n*n矩阵对角线元素之和。

样例输入

4

1 2 3 4

5 6 7 8

9 10 11 12

13 14 15 16

样例输出

34
*/
#include<stdio.h>
int main(){
    int n,i,j,a[10][10],sum = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j == i)sum += a[i][j];
        }
    }
    printf("%d\n",sum);
    return 0;
}