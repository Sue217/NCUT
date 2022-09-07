#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d",&c);
    for(a = 1;a < 14100; a++)
    {
        for(b = a;b < 14100; b++)
        {
            if(a * a + b * b == c * c)
            {
                printf("%d %d",a,b);
            }
        }
    }
    return 0;
}
