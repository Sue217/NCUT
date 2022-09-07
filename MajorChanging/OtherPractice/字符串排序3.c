#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char str[3][10],tmp[10];
    for(i=0;i<3;i++)
        scanf("%s",str[i]);
    for(i=0;i<3;i++){
        for(j=2;j>i;j--){
            if(strcmp(str[j-1],str[j]) > 0){
                strcpy(tmp,str[j-1]);
                strcpy(str[j-1],str[j]);
                strcpy(str[j],tmp);
            }
        }
    }
    for(i=0;i<3;i++)printf("%s\n",str[i]);
    return 0;
}