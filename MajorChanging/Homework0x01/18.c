/*问题描述

有一个已经排好序的正数数组（从小到大，个数在2至15个）。现输入一个数，要求按原来的规律将它插入数组中。

输入形式

输入两行。

第一行为已经排好序的正数数组，最后一个数为0，表示这一行的结束，0不属于正数数组。

第二行输入一个整数。

输出形式

输出插入后的数组。各个元素间以空格分隔。

样例输入

1 2 3 4 11 0

5

样例输出

1 2 3 4 5 11
*/
#include<stdio.h>
int main(){
    int i,j,k,a[16],n,tmp;
    for(i=0;;i++){
        scanf("%d",&a[i]);
        if(a[i] == 0)break;
    }
    scanf("%d",&n);
    a[i] = n;
    if(a[0] < a[1]){
        for(j=0;j<=i;j++){
            for(k=i;k>j;k--){
                if(a[k-1] > a[k]){
                    tmp = a[k-1];
                    a[k-1] = a[k];
                    a[k] = tmp;
                }
            }
        }
        for(j=0;j<=i;j++)printf("%d ",a[j]);
    }
    else if(a[0] > a[1]){
        for(j=0;j<=i;j++){
            for(k=i;k>j;k--){
                if(a[k-1] < a[k]){
                    tmp = a[k-1];
                    a[k-1] = a[k];
                    a[k] = tmp;
                }
            }
        }
        for(j=0;j<=i;j++)printf("%d ",a[j]);
    }
    printf("\n");
    return 0;
}