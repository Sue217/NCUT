/*
【问题描述】求任意两个不同进制非负整数的转换（2进制~16进制），所给整数在long所能表达的范围之内。不同进制的表示符号为(0，1，....，9，A，B，C，D，E，F)
注意：不同进制可能不能直接转换，如八进制与十六进制。可以考虑不同进制与十进制的转换，即借助于十进制实现任意两个不同进制的转换
【输入形式】输入只有一行，包含三个整数a，n，b。a表示其后的n是a进制整数，b表示欲将a进制整数n转换成b进制整数。a，b是十进制整数，且2=<a，b<=16
【输出形式】输出包含一行，为转换后的b进制整数。输出时字符号全部用大写表示，即（0 ，1，...，9，A，B，C，D，E，F）
【样例输入】15 AAB3 7
【样例输出】210306
【样例说明】15进制的数AAB3，转换为7进制后的数为210306*/
#include<stdio.h>
#include<string.h>
void Reserve(int before,char * num,int after){
    int i,j,yu;//p = 1;
    long sum = 0;
    char tmp[30] = {0};
    // for(i=strlen(num)-1;i>=0;i--){//before进制->10进制
    //     if(num[i]>='0' && num[i]<='9')sum += (num[i] - '0') * p;
    //     else if(num[i]>='A' && num[i]<='Z')sum += (num[i] - 'A' + 10) * p;
    //     p *= before;
    // }
    for(i=0;i<strlen(num);i++){
        if(num[i]>='0' && num[i]<='9')sum = sum * before + (num[i] - '0');
        else sum = sum * before + (num[i] - 'A' + 10);
    }
    for(i=0;sum!=0;i++){//10进制->after进制
        yu = sum % after;
        sum /= after;
        if (yu >= 10)tmp[i] = yu - 10 + 'A';
        else tmp[i] = yu + '0';
    }
    i = i-1;
    j = 0;
    while(i >= 0)num[j++] = tmp[i--];
    num[j] = 0;
    printf("%s\n",num);
}
int main(){
    int a,b;
    char n[30];
    scanf("%d%s%d",&a,n,&b);
    Reserve(a,n,b);
    return 0;
}