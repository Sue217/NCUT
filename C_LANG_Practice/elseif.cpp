#include<stdio.h>
int main()
{
	char c;
	printf("input");
	c=getchar();
	if(c<0x20)
	printf("error\n");//forget
	else if(c>'0'&&c<='9')
	printf("number\n");
	else if(c>='A'&&c<='Z')
	printf("Capital\n");
	else if(c>='a'&&c<='z')
	printf("lowercase\n");
	else printf("error\n"); 
}
