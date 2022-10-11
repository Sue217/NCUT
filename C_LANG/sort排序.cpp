#include<stdio.h>
void sort(int a,int b,int c)
{
    int t;
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    if(a>c)
    {
        t=a;
        a=c;
        c=t;
    }
    if(b>c)
    {
        t=b;
        b=c;
        c=t;
    }
    printf("%d%d%d",a,b,c);
}
int main()
{
    sort(54,32,65);
    return 0;
}
