//海伦公式
#include<stdio.h>
#include<math.h>


int main()
{
    int a, b, c;
    int p, S;
    printf("输入一个三角形的三条边：");
    scanf_s("%d%d%d", &a, &b, &c);
    if
        (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("不能构成三角形请重新输入！");
    }

    else
    {
        p = (a + b + c) / 2;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("%d", S);
    }
}
