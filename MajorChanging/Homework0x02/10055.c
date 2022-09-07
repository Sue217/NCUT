/*
【问题描述】对输入的10个整数进行排序，按从小到大的顺序输出，要求排序过程由函数完成
【输入形式】输入包括一行，共10个整数，各数之间由空格分割
【输出形式】在同一行上输出排好序的10个数，各数之间由空格分割
【样例输入】25 48 13 27 68 76 43 20 9 65
【样例输出】9 13 20 25 27 43 48 65 68 76
【样例说明】输出为排好序后的数串(注意：每个输出的数后面跟一个空格)*/
#include<stdio.h>
void Sort(int arr[]){
    int i,j,tmp;
    for(i=0;i<10;i++){
        for(j=0;j<9-i;j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
int main(){
    int i,a[10];
    for(i=0;i<10;i++)scanf("%d",&a[i]);
    Sort(a);
    for(i=0;i<10;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}