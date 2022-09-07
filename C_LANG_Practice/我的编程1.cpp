//记忆中的第一个程序
//第一个C语言程序
//并且不是Hello World 程序！
//大概是一个生成随机打乱魔方公式的程序


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a,b=100,i=0,r=0,m,n;
	system("color FC");
	printf("������Ҫ���ҹ�ʽ�ĳ���:");
	scanf("%d",&m);
	printf("������Ҫ���ҹ�ʽ�ĸ���:");
	scanf("%d",&m);
	srand((unsigned)time(NULL));
	while(n-r)
	{
		while(m-i)
	{
		loop:a=rand()%17;
		if(a==b||a==(b+6)||a==(b-6)||a==(b+12)||a==(b-12)||((i%2==0)&&(a==(b+1)||a==(b+7)||a==(b+13)||a==(b+19))))
		goto loop;
		else
		i++;
		b=a;
		switch(a)
		{
			case 0:printf("R");break;
		    case 1:printf("L");break;
		    case 2:printf("U");break;
		    case 3:printf("D");break;
		    case 4:printf("F");break;
		    case 5:printf("B");break;
		    case 6:printf("R'");break;
		    case 7:printf("L'");break;
		    case 8:printf("U'");break;
		    case 9:printf("D'");break;
		    case 10:printf("F'");break;
		    case 11:printf("B'");break;
		    case 12:printf("R2");break;
		    case 13:printf("L2");break;
		    case 14:printf("U2");break;
		    case 15:printf("D2");break;
		    case 16:printf("F2");break;
		    case 17:printf("B2");break;
		}
	}
	printf("\n\n");
	i=0;
	r++;	
	}
	
	return 0;
}
