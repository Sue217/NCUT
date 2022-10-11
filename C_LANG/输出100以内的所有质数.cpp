//写一个函数，实现质数的判断，并在主函数中调用，输出100以内的所有质数
#include<stdio.h>
int main()
{
    int i;
    int j;
    int flag = 1;

    for(i = 2;i <= 100;i++)
    {
        for(j = 2;j <= i / 2;j++)
 {
     if(i % j ==0)
     {
         flag = 0;
  break;
     }
 }
     if(flag == 1)
     {
        printf("%d\t",i);
     }
     flag = 1;

    }

    return 0;
}
