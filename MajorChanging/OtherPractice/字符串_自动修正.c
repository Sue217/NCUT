//要求将该字符串中的所有小写字母变成大写字母并输出

#include<stdio.h>
#include<string.h>
int main(){
    char str[105] = {0};
    gets(str);
    for(int i=0;i<strlen(str);i++)
        if(str[i]>='a'&&str[i]<='z')
            str[i] -= 32;
    puts(str);
    return 0;
}