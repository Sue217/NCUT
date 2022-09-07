#include<stdio.h>
void my_strcpy(char * str1,char * str2){
    while(*str1++ = *str2++);//str2 != '\0';*str1 = *str2;str1++,str2++;
    str1 = '\0';
}

int main(){
    char str1[] = "abcd";
    char str2[10] = {0};
    my_strcpy(str2,str1);
    puts(str2);
}