//结构体2
#include<stdio.h>
#include<string.h>
struct Student
{
	int id;
	char name[32];
	char classes[32];
	char course[32];
	float score;
};
int main()
{
	Student stu;
	stu.id = 202001;
	strcpy_s(stu.name, "BOBLT");
	strcpy_s(stu.classes, "机实验20");
	strcpy_s(stu.course, "Language C");
	stu.score = 100;
	printf("%d,%s,%s,%s,%lf\n", stu.id, stu.name, stu.classes, stu.course, stu.score);
	return 0;
}