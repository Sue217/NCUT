//ShellSort!!!
//空间复杂度O(1)
//时间复杂度 目前无法用数学手段确定 最坏O(n^2) n在某个范围内达O(n^1.3)优于直接插入排序
//稳定性 不稳定 并且只能针对顺序表实现,链表不可以使用!

#include<stdio.h>
void ShellSort(int A[],int n){
    int d,i,j;//d:增量
    for(d=n/2;d>=1;d/=2)//步长变化
        for(i=d+1;i<=n;++i)//i+=d遍历子表1后回到子表2第二个元素即i=d+2(存疑)
            if(A[i] < A[i-d])
                A[0] = A[i];
                for(j=i-d;j>0 && A[0]<A[j];j-=d)
                    A[j+d] = A[j];
                A[j+d] = A[0];
}