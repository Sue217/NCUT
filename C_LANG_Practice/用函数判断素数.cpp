#include <stdio.h> 
int max(int x)
{
	int i,f=1;
	for(i=2;i<x;i++)
		if(x%i==0) f=0;
  if(f==1) return 1;
  else return 0;
}
int main(void)
{int a,b,c;
 a=2;
 b=3;
 c=max(a);
 printf("The max is %d %d %d",c,max(a+a),max(22));
 return 0;
}
