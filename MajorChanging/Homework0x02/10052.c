/*
【问题描述】对给定的两组数（每组数包括2个整数），分别计算出两组数的最大公约数和最小公倍数的和
如: 20、12为第一组，28、7为第二组。第一组数的最大公约数为4，最小公倍数为60;第二组数的最大公约数为7，最小公倍数为28
所以两组数的最大公约数之和为11，两组数的最小公倍数之和为88。要求最大公约数和最小公倍数分别由功能函数完成。
【输入形式】输入包括两行，每行为一组，每组两个整数。
【输出形式】输出包括两行，第一行为两组数的最大公约数之和，第二行为两组数的最小公倍数之和。
【样例输入】
    20 12
    28  7
【样例输出】
    11
    88
【样例说明】这两组数的最大公约数之和为11，最小公倍数之和为88(注意: 输出的两个数每个数后面均以换行符结束)*/
#include<stdio.h>
int Gcd(int a,int b){
    int max = -1;
    while(max != 0){
        if(max == 0)break;
        max = a % b;
        a = b;
        b = max;
    }
    return a;
}
int Lcm(int a,int b){
    int i,tmp;
    if(a > b){
        tmp = a;
        a = b;
        b = tmp;
    }
    //a <= b
    for(i=b;i%a!=0 || i%b!=0;i++);
    return i;
}
int main(){
    int a,b,m,n;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&m,&n);
    printf("%d\n",Gcd(a,b) + Gcd(m,n));
    printf("%d\n",Lcm(a,b) + Lcm(m,n));
    return 0;
}