//对输入两个16进制数（两个字符串），将其转化成为10进制数求和
#include<stdio.h>
#include<string.h>
int a(int y){
	int n=1;
	for(;y>0;y--)
		n*=16;
	return n;
}
int Transform(char st[100],int x){
	int s=0,i=0,y;
	for(;x>=0;x--,i++){
		if(st[x]>=48&&st[x]<=57) y=st[x]-48;   
		if(st[x]>=97&&st[x]<=103) y=10+(st[x]-97);   
		s+=y*a(i);
	}
	return s;
}
char * strcpy(char * strDest,const char * strSrc){
	if((NULL == strDest) || (NULL == strSrc))throw("Invalid Argument(s)!");
	char *strDestCopy = strDest;
	while((*strDest++ = *strSrc++) != '\0');
	return strDestCopy;
}
int main(){
	char * strcpy(char * strDest,const char * strSrc);
	char a[100],b[100];
	int sum,lena,lenb;
	int *p,*q;
	scanf("%s",&a);
	scanf("%s",&b);
	*p = strlen(a);
	*q = strlen(b);
	sum=Transform(a,--(*p))+Transform(b,--(*q));//Is it right?
	printf("%d",sum);
	return 0;
}
