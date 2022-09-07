/*给出n(n≤100)和n个整数 ai(0 ≤ a ≤ 1000),求这n个整数中最小值是什么*/
#include<stdio.h>
int main(){
    int n,a[105],min;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    min = a[0];
    for(int i=1;i<n;i++){
        if(a[i] < min)
            min = a[i];
    }
    printf("%d\n",min);
    return 0;
}