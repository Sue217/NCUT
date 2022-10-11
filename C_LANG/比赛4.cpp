#include<stdio.h>
int main()
{
    int n;
    int sum=0;
   	int max=-1;
   	int min=101;    
   	double b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;     
        scanf("%d",&a);
        sum += a;
        if(min > a)
        {
            min = a;
        }
        if(max < a)
        {
            max = a;
        }
        if(i>=3)
        {
            b=(sum-max-min)/(i-2);
            printf("%.2f\n",b );
        }
    }
    return 0;
}
