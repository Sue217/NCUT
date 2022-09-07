

#include <iostream>
//5个人坐，问第五个人多少岁，他说比第四个人大两岁
//问第四个人岁数，说比第三个人大两岁
//以此类推问每一个人都比下一个人大两岁
//问第一个人是10岁
//问第五个人的年龄
int year(int n)
{
    return n == 1 ? 10 : year(n - 1) + 2;//OR if(n==1){return 1;} else{n=(n-1)+2;}
}
int main()
{
    printf("第五人年龄是%d岁",year(5));
    return 0;
}

