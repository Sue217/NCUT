//red yellow blue green white
/*After sorted:
blue
green
red
white
yellow
*/
#include<stdio.h>
#include<string.h>
int main(){
	int i,j;
	char s[5][85],t[85];
	for(i=0;i<5;i++)
		scanf("%s",s[i]);
	for(i=0;i<5;i++)
		for(j=4;j>i;j--)
			if(strcmp(s[j-1],s[j])>0){//字符串的比较
				strcpy(t,s[j-1]);//字符串的复制
				strcpy(s[j-1],s[j]);
				strcpy(s[j],t);
			}
	printf("After sorted:\n");
	for(i=0;i<5;i++)
		printf("%s\n",s[i]);
	return 0;
} 