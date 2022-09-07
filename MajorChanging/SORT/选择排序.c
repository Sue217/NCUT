//SelectSort!!
//空间复杂度 O(1)
//时间复杂度 O(n^2)与n无关
//稳定性 不稳定
//可用于链表
#include<stdio.h>
int main(){
    void SelectSort(int A[],int n);
    void swap(int *x,int *y);
    int A[10];
    for(int i=0;i<10;i++)
        scanf("%d",&A[i]);
    SelectSort(A,10);
    for(int i=0;i<10;i++)
        printf("%5d",A[i]);
    return 0;
}
// void swap(int *x,int *y){
//     int *tmp;
//     tmp = x;
//     x = y;
//     y = tmp;
// }
void swap(int * x,int * y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void SelectSort(int A[],int n){
    int min;
    for(int i=0;i<n-1;i++){//n-1趟
        min = i;//min元素位置
        for(int j=i+1;j<n;j++)//选最小元素
            if(A[j] < A[min])min = j;//更新min元素位置
        if(min != i)swap(&A[i],&A[min]);
    }
}