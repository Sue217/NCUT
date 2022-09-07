#include<stdio.h>
int main(){//float数据扩充
    float cola = 9.23;
    float xuebi = 8.23;
    float carry = 168.48;
    int Cola = (int)(cola*100);
    int Xuebi = (int)(xuebi*100);
    int Carry = (int)(carry*100);
    printf("Cola = %d",Carry/Cola);
    printf("Xuebi = %d",Carry/ Xuebi);
}