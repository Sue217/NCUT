#include<stdio.h>
void BubbleSort1(int a[],int size){
    int i,j,tmp;
    for(i=0;i<size-1;i++)
        for(j=0;j<size-1-i;j++)
            if(a[j] > a[j+1]){//little -> large
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
}
void BubbleSort2(int b[],int size){
    int i,j,tmp;
    for(i=0;i<size-1;i++)
        for(j=size-1;j>i;j--)
            if(b[j-1] > b[j]){//little -> large
                tmp = b[j-1];
                b[j-1] = b[j];
                b[j] = tmp;
            }
}
void BubbleSort3(int c[],int size){
    int i,j,tmp;
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size-1;j++)
            if(c[j-1] > c[j]){//string:if(strcmp(a[j-1],a[j]) < 0)
                tmp = c[j-1];
                c[j-1] = c[j];
                c[j] = tmp;
            }
}

int main(){
    int arr[] = {2,8,6,3,7,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort1(arr,n);
    for(int i=0;i<n;i++)printf("%d",arr[i]);
    printf("\n");
    BubbleSort2(arr,n);
    for(int i=0;i<n;i++)printf("%d",arr[i]);
    printf("\n");
    BubbleSort3(arr,n);
    for(int i=0;i<n;i++)printf("%d",arr[i]);
    printf("\n");
    return 0;
}
/*Out:
2235678
2235678
2235678*/