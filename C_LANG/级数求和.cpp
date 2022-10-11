#include<stdio.h>
int main()
{
    int  n,k;
    double sn=0;
    scanf("%d",&k);
    for(n=1;;n++)
    {
        sn+=1.0/n;
        if(sn>k)
        {
            break;
        }
    }
    printf("%d",n);
    return 0;
}
