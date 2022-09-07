//"    abcdef    " => abcdef(6)
#include<stdio.h>
#include<string.h>
int main(){
    int begin = 0,end,len;
    char str[] = "    abcdef     ";
    end = strlen(str) - 1;
    if(end < 0)return;
    while(str[begin] == ' ' && str[begin] != '\0')begin++;
    while(str[end] == ' ')end--;
    len = end - begin + 1;
    for(int i=begin;i<=end;i++)
        printf("%c",str[i]);
    printf("\n");
    printf("Length = %d\n",len);
    return 0;
}