/*问题描述

找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小，也可能没有鞍点。

输入形式

第一行，输入两个正整数m和n，表示二维数组有m行n列。（1=<m,n<=10）

从第2到m+1行输入二维数组的各个元素，每行输入元素的个数为n个。

输出形式

输出一行，若有鞍点，则输出鞍点所处的行、列和鞍点值（各个数据间以空格分隔），若没有鞍点，则输出no。

样例输入

3 5

3 2 1 5 -1

1 5 8 6 1

5 6 7 7 9

样例输出

0 3 5

*/
#include<stdio.h>
int main(){
    int i,j,k,a[12][12],m,n,row,min,PAN,flag = 0;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    }
    for(i=0;i<m;i++){
        PAN = a[i][0];
        row = 0;
        for(j=1;j<n;j++){
            if(PAN < a[i][j]){
                PAN = a[i][j];
                row = j;
            }
        }
        min = a[0][row];
        for(k=1;k<m;k++)
            if(min > a[k][row])min = a[k][row];
        if(min == PAN){
            printf("%d %d %d ",i,row,PAN);
            flag = 1;
        }
    }
    if(flag == 0)printf("no");
    printf("\n");
    return 0;
}