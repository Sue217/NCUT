//InsertSort
//每次将一个待排序元素按关键字大小插入前面已排好序的子序列中
#include<stdio.h>

void InsertSort(int A[],int n){
    int i,j,temp;
    for(i=1;i<n;i++)//第一个元素已排好
        if(A[i] < A[i-1]){
            temp = A[i];
            for(j=i-1;j>=0 && A[j]>temp;--j)//检查已经前面排好元素
                A[j+1] = A[j];//所有大于temp元素向后移位
            A[j+1] = temp;//复制到插入位置
        }
        
}