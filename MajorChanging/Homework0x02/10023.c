/*
【问题描述】对给定的4个整数进行排序，将由小到大的顺序输出。
【输入形式】一行中有4个整数，整数之间用空格分隔。
【输出形式】按升序输出，各整数之间用一个空格分隔,最后一位数后也要有空格。
【样例输入】25 314 18 27
【样例输出】18 25 27 314
【样例说明】在控制台输入25 314 18 27，输出结果是18 25 27 314。
*/
#include<stdio.h>
int main(){
    int arr[4];
    int i,j,tmp;
    for(i=0;i<4;i++)scanf("%d",&arr[i]);
    for(i=0;i<4;i++){
        for(j=0;j<3-i;j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for(i=0;i<4;i++)printf("%d ",arr[i]);
    printf("\n");
    return 0;
}