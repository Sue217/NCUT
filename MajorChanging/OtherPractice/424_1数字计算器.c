//完成一个简单的计算器，可以实现两个数字的加、减、乘、除、取余五种运算
#include<stdio.h>
int main(){
    int num1,num2,res;
    char sign;
    scanf("%d%c%d",&num1,&sign,&num2);
    if(sign == '+'){
        res = num1 + num2;
        printf("%d\n",res);
    }
    else if(sign == '-'){
        res = num1 - num2;
        printf("%d\n",res);
    }
    else if(sign == '*'){
        res = num1 * num2;
        printf("%d\n",res);
    }
    else if(sign == '/'){
        res = num1 / num2;
        printf("%d\n",res);
    }
    else if(sign == '%'){
        res = num1 % num2;
        printf("%d\n",res);
    }
    else printf("Error\n");
    return 0;
}