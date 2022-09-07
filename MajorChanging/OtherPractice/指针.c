//指针变量和指针指向内存块 不是一个东西!!!
#include<stdio.h>
int main(){
    char *p = NULL;
    char buf[] = "abcdef";

    printf("p1 = %d\n",p);
    //change pointer variable's value
    p = buf;
    printf("p2 = %d\n",p);
    p++;//change pointer's direction
    printf("buf1 = %s\n",buf);
    printf("p2 = %d\n",p);

    printf("*p = %c\n",*p);
    //change memory of pointer point
    buf[1] = '1';//change value of variable
    printf("buf2 = %s\n",buf);
    printf("p3 = %d\n",p);

    *p = 'm';//change point of pointer
    printf("buf3 = %s\n",buf);
    printf("p4 = %d\n",p);

    printf("**********************\n");
    char *ptr;
    char str[] = "12345abcde";
    // int *qtr;
    int A[10] = {0,1,2,3,4,5,6};
    ptr = str;
    printf("*ptr = %c\n",*ptr);
    ptr ++;
    printf("*ptr = %c\n",*ptr);
    ptr ++;
    printf("*ptr = %c\n",*ptr);
    ptr += 5;
    printf("*ptr = %c\n",*ptr);
    printf("%d\n",&buf[0]);
    printf("%d\n",&buf[1]);
    printf("%d\n",&buf[4]);
    printf("%d\n",&A[0]);
    printf("%d\n",&A[1]);
    printf("%d\n",&A[4]);
}

/*output:
p1 = 0
p2 = -516998735
buf1 = abcdef
p2 = -516998734
*p = b
buf2 = a1cdef
p3 = -516998734
buf3 = amcdef
p4 = -516998734
**********************
*ptr = 1
*ptr = 2
*ptr = 3
*ptr = c
-516998735(+1)
-516998734(+3)
-516998731
-516998720(+4)
-516998716(+12)
-516998704
*/