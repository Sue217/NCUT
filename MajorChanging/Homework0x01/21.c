/*问题描述

求方程ax2+bx+c=0的根。用3个函数分别求当b*b﹣4ac大于0、等于0和小于0时的根并输出结果。
从主函数输入a、b、c的值。（注意此题没有说明是一元二次方程，所以要考虑a为零的情况）。

输入形式

输入一行，只包括3个浮点数（请在程序中设置为double数据类型），即a、b、c的值。

输出形式

输出一行，给出方程的根，小数点保留两位。若为一个根，则输出一个根，若有两个实根，则输出两个实根（实根大的先输出），两个实根间以空格分隔。若有两个虚根，则输出两个虚根（虚根大的先输出），两个虚根间以空格分隔。

样例输入

1 2 3

样例输出

-1.00+1.41i  -1.00-1.41i
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void DB(double a,double b,double c){
    double x1,x2;
    x1 = (-b + sqrt(b*b-4*a*c)) / (2*a);
    x2 = (-b - sqrt(b*b-4*a*c)) / (2*a);
    printf("%.2lf %.2lf\n",x1,x2);
}
void DE(double a,double b,double c){
    double x = -b / (2*a);
    printf("%.2lf\n",x);
}
void DL(double a,double b,double c){
    double real,imag;
    real = -b / (2*a);
    imag = (sqrt(-(b*b-4*a*c))) / (2*a);
    printf("%.2lf+%.2lfi %.2lf-%.2lfi\n",real,imag,real,imag);
}
int main(){
    double a,b,c,dert;
    scanf("%lf%lf%lf",&a,&b,&c);
    dert = b * b - 4 * a * c;
    if(a < 1e-6)printf("%.2lf\n",-c/b);
    else{
        if(fabs(dert) <= 1e-6)DE(a,b,c);
        else{
            if(dert > 1e-6)DB(a,b,c);
            else DL(a,b,c);
        }
    }
    return 0;
}