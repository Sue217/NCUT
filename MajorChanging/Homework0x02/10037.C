/*
问题描述】图案输出
【输入形式】输入打印符号，初始位置和行数，以空格隔开。
【输出形式】按照指定的打印符号，从指定的初始位置开始，打印一个（2*行数-1）行的菱形图案
【样例输入】* 0 4
【样例输出】

   *
  ***
 *****
*******
 *****
  ***
   *

*/
#include <stdio.h>
int main(){
    int i,j,k,m,n;
    char ch;
    scanf("%c%d%d",&ch,&m,&n);
    for(i=0;i<m-1;i++)printf("\n");
    for(i=0;i<n;i++){
        for(j=n-i-1;j>0;j--)printf(" ");
        for(k=0;k<2*i+1;k++)printf("%c",ch);
        printf("\n");
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<i+1;j++)printf(" ");
        for(k=0;k<2*(n-i)-3;k++)printf("%c",ch);
        printf("\n");
    }
    return 0;
}