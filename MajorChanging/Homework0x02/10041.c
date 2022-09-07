/*
【问题描述】打印出杨辉三角形的前n行。
【输入形式】输入一个正整数n(n<20)。
【输出形式】杨辉三角形，每个输出的数后面跟一个空格。
【样例输入】5
【样例输出】
 1
 1 1
 1 2 1
 1 3 3 1
 1 4 6 4 1
 */
#include<stdio.h>
int main(){
    int i,j,n,arr[20][20];
    scanf("%d",&n);
    arr[0][0] = 1;
    for(i=1;i<n;i++){
        arr[i][0] = 1;
        for(j=1;j<i;j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
        arr[i][j] = 1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}