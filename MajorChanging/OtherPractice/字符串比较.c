/*
Happy Help
Help Help
Help Happy

- 4
0
4
*/

#include<stdio.h>
#include<string.h>
int stringcmp(char *str1,char *str2){
	int i=0,p=0;
	while(*str1!=NULL||*str2!=NULL){
		if(*str1!=*str2){
			p=*str1-*str2;
			break;
		}
		*str1++;
		*str2++;
	}
	return p;
}
int main(){
	int n,i,x,st[100];
	char str1[100],str2[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%s",str1,str2);
		st[i]=stringcmp(&str1[0],&str2[0]);
	}
	for(i=0;i<n;i++)
		printf("%d\n",st[i]);
	return 0;
}
