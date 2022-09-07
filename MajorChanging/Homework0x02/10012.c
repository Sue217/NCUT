#include<stdio.h>
#define CG 28.9
#define DSA 32.7
#define DL 45.6
#define CPP 78
#define AI 35
#define CA 86.2
#define CF 27.8
#define OS 43
#define CN 56
#define JAV 65
int main(){
    int i,a[10];
    float sum = 0;
    for(i=0;i<10;i++)scanf("%d",&a[i]);
    sum = CG*a[0]+DSA*a[1]+DL*a[2]+CPP*a[3]+AI*a[4]+CA*a[5]+CF*a[6]+OS*a[7]+CN*a[8]+JAV*a[9];
    printf("%.2f\n",sum);
    return 0;
}