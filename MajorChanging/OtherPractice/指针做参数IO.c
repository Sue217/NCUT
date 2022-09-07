#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void f(char * p/* in */){
    //给p指向内存copy
    strcpy(p,"abcd");//strcpy被调
}
void fun(char ** p/* out */,int * len){//fun被调
    if(p == NULL)return;
    char * tmp = (char *)malloc(100);//
    if(tmp == NULL)return;
    else strcpy(tmp,"abcdefg");

    //间接赋值
    *p = *tmp;
    *len = strlen(tmp);
}
int main(){
    //输入 主调函数分配内存
    char buf[10] = {0};
    f(buf);
    printf("%s\n",buf);

    //输出 被调函数分配内存 地址传递
    char * p = NULL;
    int len = 0;
    fun(&p,&len);//p指向空 p地址不为空
    if(p != NULL)printf("%s%d",p,len);
}