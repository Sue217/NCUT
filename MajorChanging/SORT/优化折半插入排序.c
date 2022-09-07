#include<stdio.h>
void InsertSort(int A[],int n){
    int i,j,low,high,mid;
    for(i=2;i<=n;i++){
        A[0] = A[i];
        low = 1;high = i-1;//折半查找的范围
    }
    while(low <= high){
        mid = (low + high) >> 1;
        if(A[0] > A[mid])high = mid - 1;//查左半表
        else low = mid + 1;//查右半表
    }
    for(j=i-1;j>=high+1;--j)//low = high+1
        A[j+1] = A[j];//后移
    A[high+1] = A[0];//low = high+1
    //插入
}