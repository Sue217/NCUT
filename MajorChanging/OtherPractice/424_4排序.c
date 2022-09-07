/*给出2个序列A={a[1]，a[2]，…，a[n]}，B={b[1]，b[2]，…，b[n]}
从A、B中各选出n个元素进行一一配对（可以不按照原来在序列中的顺序）
并使得所有配对元素差的绝对值之和最大*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n,* a,* b,i,j,tmp,sum = 0;
    scanf("%d",&n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=n-1;j>i;j--){
            if(a[j] < a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
            if(b[j] > b[j-1]){
                tmp = b[j];
                b[j] = b[j-1];
                b[j-1] = tmp;
            }
        }
    }
    for(i=0;i<n;i++)
        sum += abs(a[i] - b[i]);
    printf("%d\n",sum);
    free(a);
    free(b);
    return 0;
}