/*
【问题描述】The digital root of a positive integer is found by summing the digits of the integer.
If the resulting value is a single digit then that digit is the digital root.
If the resulting value contains two or more digits,those digits are summed and the process is repeated.
This is continued as long as necessary to obtain a single digit.
For example, consider the positive integer 24.  Adding the 2 and the 4 yields a value of 6.
Since 6 is a single digit, 6 is the digital root of 24.
Now consider the positive integer 39. Adding the 3 and the 9 yields 12,
since 12 is not a single digit, the process must be repeated.
Adding the 1 and the 2 yields 3, a single digit and also the digital root of 39.
【输入形式】
The input file will contain a list of positive integers,one per line.
The end of the input will be indicated by an integer value of zero.
【输出形式】
For each integer in the input, output its digital root on a separate line of the output.
【样例输入】
24
39
0
【样例输出】
6
3
*/
#include<stdio.h>
int main(){
    int i,j,k,m,n,a[100],b[100];
    i = 0;
    while(scanf("%d",&a[i]) != 0){
        if(a[i] == 0)break;
        b[i] = a[i];
        i++;
    }
    for(j=0;j<i;j++){
        m = 0;
        n = 0;
        while (b[j] > 0){
            m += b[j] % 10;
            b[j] /= 10;
        }
        if(m < 10)printf("%d\n",m);
        else{
            while (m > 0){
                n += m % 10;
                m /= 10;
            }
            printf("%d\n",n);
        }
    }
    return 0;
}