#include<stdio.h>
double a,b,c,d;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    double m,n,k,x1,x2;
    int i,j=0;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for (i=-100;i<=100;i++)
    {
      m=i;
      n=i+1;
      x1=f(m);
      x2=f(n);
      if (x1==0)
      {
          printf("%.2lf ",m);
          j++;
      }
      if (x1*x2<0)
      {
          while (n-m>=0.001)
          {
              k=(m+n)/2;
              if (f(k)*f(n)<=0)
              m=k;
              else
              n=k;
          }
          printf("%.2lf ",n);
          j++;
      }
      if (j==3)
      break;
    }
    return 0;
}


