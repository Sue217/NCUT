/*
hello how are yes.
h H
es ou
0 0
Hello How are you.
*/

#include<stdio.h>
#include<string.h>
void swap(char text[],char a[],char b[]){
	char *str=text,back[20];
	while((str=strstr(str,a))!=NULL){
		strcpy(back,str+strlen(a));
		*str=0;
		strcat(text,b);
		strcat(text,back);
		str+=strlen(b);
	}
}
int main(){
	char text[80],a[20],b[20];
	gets(text);
	while(1){
		scanf("%s",a);
		scanf("%s",b);
		if(strcmp(a,"0")==0&&strcmp(b,"0")==0) break;
		swap(text,a,b);
	}
	puts(text);
	return 0;
}