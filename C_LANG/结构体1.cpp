//结构体1
#include<stdio.h>

struct Motor
{
	float pos;//位置
	float speed;//速度
	float torque;//扭矩
};
struct Axis
{
	int id;
	float rate;
	Motor motor;
};

int main()
{
	Axis axis;
	axis.id = 1;
	axis.rate = 20;
	//Motor m = { 30,150,6 };
	//axis motor = m;
	axis.motor.pos = 20;
	axis.motor.speed = 100;
	axis.motor.torque = 5;
	printf("轴号:%d\n", axis.id);
	printf("减速比:%f\n", axis.rate);
	printf("电机位置:%f\n", axis.motor.pos);
	printf("电机速度:%f\n", axis.motor.speed);
	printf("电机扭矩:%f\n", axis.motor.torque);
}