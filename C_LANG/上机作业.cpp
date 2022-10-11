#include"BOBLT.h"//自定义头文件
int main()
{
	printf("%.2lf\n", power(3, 5));
	for (int i = 2;i <= 100;i++)
	{
		if (Prime_number(i))
		{
			printf("%d\t", i);
		}
	}
	printf("\n");
	printf("%.2lf\n%.2lf\n%.2lf\n", Circle_area(2),Ball_area(2),Ball_volume(2));

	printf("\n");
	Solve_equation(1, -2, 1);
	
}
