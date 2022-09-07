#include<stdio.h>

void fun1(int b){
        b = 20;
    }
void fun2(int *p){
    *p = 20;
}
int main(){
    int a = 10;
    // int *q = 0x11234
    fun1(a);//值传递 将a的值赋给b 对b修改 与a无关
    printf("%d\n",a);
    fun2(&a);//地址传递 将p指向a的地址 *p对a（内存）操作 修改a数值
    printf("%d",a);
    // fun3(q);值传递
}
//10 20