#include<stdio.h>

/*
getchar == scanf("%c",&ch);
putchar(ch) == printf("%c",ch);
*/

int main(){
    char ch;
    while((ch = getchar()) != '\n'){
        if(ch == ' ')putchar(ch);
        else putchar(ch + 1);
        ch = getchar();
    }
    // putchar(ch);
    return 0;
}