

#include <stdio.h>

int main()
{
    int a = 100;
    int* p;
    p = &a;
    printf("%d\n",*p);
    a = 200;
    printf("%d\n",*p);
    *p += 10;
    printf("%d\n",*p);
    return 0;

}

