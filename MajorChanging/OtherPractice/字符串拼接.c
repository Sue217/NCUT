#include<stdio.h>
#include<string.h>
int main1(){
    int i,j;
    char str1[20],str2[20],str[50];
    for(i=0;(str1[i]=getchar())!='\n';i++);
    for(j=0;(str2[j]=getchar())!='\n';j++);
    for(i=0;i<strlen(str1)-1;i++)str[i] = str1[i];
    for(j=0;j<strlen(str2);j++)str[strlen(str1)+j] = str2[j];
    str[strlen(str1)+strlen(str1)] = '\0';
    printf("%s",str);
    return 0;
}
char cat(char * str1,char * str2){
    int i,j;
    char str[50];
    for(i=0;i<strlen(str1)-1;i++)str[i] = str1[i];
    for(j=0;j<strlen(str2);j++)str[strlen(str1)+j] = str2[j];
    str[strlen(str1)+strlen(str1)] = '\0';
    return str;
}
void str_cat0(char * str1,char * str2){
    int k;
    for(k=0;k<strlen(str2);k++)str1[strlen(str1)+k] = str2[k];
}
char * str_cat(char * strDest,char * strScr){
    while(*strDest)strDest++;
    while(*strDest++ = *strScr++)NULL;
    return strDest;
}
int main(){
    int i,j,k;
    char str1[50],str2[50];
    for(i=0;(str1[i]=getchar())!='\n';i++);
    for(j=0;(str2[j]=getchar())!='\n';j++);
    str_cat(str1,str2);
    for(k=0;k<(strlen(str1)+strlen(str2));k++)printf("%c",str1);
    return 0;
}