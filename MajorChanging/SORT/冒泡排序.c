//BubbleSort!!!
//空间复杂度O(1)
//时间复杂度 最好:O(n) 一般(最坏):O(n^2)
//稳定性 稳定 可适用于链表

#include<stdio.h>
void swap(int * x,int * y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void BubbleSort_ofNegativeSequence(int A[],int n){
    int i,j;
    int flag;
    for(i=0;i<n-1;i++)//趟
        flag = 0;//本趟是否冒泡交换
        for(j=n-1;j>i;j--)//一趟冒泡
            if(A[j-1] > A[j]){
                swap(A[j-1],A[j]);
                flag = 1;//交换
            }
        if(flag == 0)return;//未交换,已有序
}
void BubbleSort_ofPositiveSequence(int A[],int n){
    int p,q;
    int flag;
    for(p=0;p<n-1;p++)
        flag = 0;
        for(q=p+1;q<n;q++)
            if(A[q-1] > A[q]){
                swap(A[q-1],A[q]);
                flag = 1;
            }
        if(flag == 0)return;
}