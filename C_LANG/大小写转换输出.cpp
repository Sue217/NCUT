// 输入一个大写字母转换成小写字母输出显示

#include <stdio.h>
int main()
{

	char a;
	scanf_s("%c", &a);


	int num = a - 32;
	int name = num;
	printf("%c", name);

}