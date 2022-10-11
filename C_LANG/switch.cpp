#include<stdio.h>
int main()
{
	int score;
	printf("input score:");
	scanf("%d",&score);
	if((score>=0)&&(score<=100))
	{
		switch(score/10){
			case 10:
			case 9:printf("A\n");break;
			case 8:printf("B\n");break;
			case 7:printf("C\n");break;
			case 6:printf("D\n");break;
			default:printf("U\n");
		}
	}
	else printf("Error");
}
