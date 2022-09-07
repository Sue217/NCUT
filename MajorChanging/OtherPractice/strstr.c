#include<stdio.h>
#include<string.h>
int main(){
    int num = 0;
    char str[100],ch[100];
    char * p = str;
    gets(str);
    gets(ch);
    p = strstr(str,ch);
    while(p != NULL){//原字符串中是否包含目标字符串
        if(*p == 0)break;//原字符串是否结束
        else{
            num++;//统计目标字符串个数
            p += strlen(ch);
        }
        p = strstr(p,ch);
    }
    printf("%d",num);
    return 0;
}

/*int main(){
    int num = 0;
    char * str = "abcdabbcd9480abcdghoabcd";
    while((str = strstr(str,"abcd")) != NULL){
        if(*str == 0)break;
        else{
            num++;
            str += strlen("abcd");
        }
    }
    printf("%d",num);
    return 0;
}*/