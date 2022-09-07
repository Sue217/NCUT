#include<stdio.h>
#include<string.h>
int main(){
    FILE *file = fopen("Phonebook.csv","a");
    if(file == NULL)return 1;

    char Name[25],Number[25];
    scanf("%s%s",Name,Number);
    
    fprintf(file,"%s %s\n",Name,Number);
    fclose(file);
}