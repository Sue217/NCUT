//QuickSort!!!
//空间复杂度 最好 O(logn)一般 O(递归层数)最坏 O(n)
//时间复杂度 最好 O(nlogn)一般 O(n*递归层数)(二叉树高度)最坏O(n^2)
//稳定性 稳定
//若待排序序列是正OR逆序,快排效率最低性能最差(枢轴划分两个很不均匀部分,递归深度增加)
//优化1选取头中尾中间值作为枢轴元素2随机选取枢轴元素
//平均性能最优秀

#include<stdio.h>
int Partition(int A[],int low,int high){
    int pivot = A[low];//第一个元素作为枢轴
    while(low < high){//搜索枢轴最终位置
        while(low<high && A[high]>= pivot)--high;
        A[low] = A[high];//比枢轴小移至左
        while(low<high && A[low]<= pivot)++low;
        A[high] = A[low];//比枢轴大移至右
    }
    A[low] = pivot;//最终位置
    return low;
}

void QuickSort(int A[],int low,int high){
    if(low < high){//递归跳出条件
        int pivotos = Partition(A,low,high);//划分
        QuickSort(A,low,pivotos-1);//划分左子表
        QuickSort(A,pivotos+1,high);//划分右子表
    }
}