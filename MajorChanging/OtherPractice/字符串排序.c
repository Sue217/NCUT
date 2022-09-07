/*
zhangsan
liyang
wangxiao
liqing
wuhui

liqing
liyang
wangxiao
wuhui
zhangsan
*/

#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,min;
	char st[30][20],a[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%c",&st[i]);
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++)
			if(strcmp(st[min],st[j])>0) min=j;
		strcpy(a,st[min]);
		strcpy(st[min],st[i]);
		strcpy(st[i],a);
	}
	for(i=0;i<n;i++)
		printf("%s\n",st[i]);
	return 0;
}
