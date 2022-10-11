#include<stdio.h>
int main()
{
    int a,b,n;
    int m=0;
    scanf("%d",&n);
    for(a=1;a<=n;a++)
    {
    	int c=0;
        b=a;
        while(b>0)
        {
            c+=b%10;
            b/=10;
        }
        if(c==9)
        	m++; 
    }
    printf("%d\n",m);
    return 0;
}
