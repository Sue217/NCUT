//直接插入排序（带哨兵）
//空间复杂度O(1)
//平均时间复杂度O(n^2)最好O(n)
//稳定性：稳定

#include<stdio.h>
void InsertSort(int A[],int n){
    int i,j;
    for(i=2;i<n;i++)
        if(A[i]<A[i-1]){
            A[0] = A[i];//复制为哨兵A[0]不存放元素
            for(j=i-1;A[0]<A[j];--j)
                A[j+1] = A[j];
            A[j+1] = A[0];//复制到插入位置
        }
}