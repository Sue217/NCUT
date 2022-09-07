/*问题描述

用筛选法求N之内的素数。（N小于等于100）。

筛选法又称筛法，是求不超过自然数N（N>1）的所有质数的一种方法。

具体做法是：先把N个自然数按次序排列起来。1不是质数，也不是合数，要划去。
第二个数2是质数留下来，而把2后面所有能被2整除的数都划去。
2后面第一个没划去的数是3，把3留下，再把3后面所有能被3整除的数都划去。
3后面第一个没划去的数是5，把5留下，再把5后面所有能被5整除的数都划去。
这样一直做下去，就会把不超过N的全部合数都筛掉，留下的就是不超过N的全部质数。

输入形式

输入一行，只包括一个正整数N。

输出形式

输出一行，给出从1到N之间所有的素数。（包括1和N）。

样例输入

11

样例输出

2 3 5 7 11
*/
#include<stdio.h>
int main(){
    int i,j,k,N,a[100];
    scanf("%d",&N);
    for(i=0;i<N;i++)a[i] = i + 1;
    for(i=1;i<N;i++){
        if(a[i] == 0)continue;
        else{
            for(j=i+1;j<N;j++){
                if(a[j] % a[i] == 0)a[j] = 0;
            }
        }
    }
    for(k=1;k<N;k++){
        if(a[k] != 0)printf("%d ",a[k]);
    }
    printf("\n");
    return 0;
}
// Wrong Answer
/*int main(){
    int i,N;
    scanf("%d",&N);
    if(N > 7){
        printf("2 3 5 7 ");
        for(i=8;i<=N;i++){
            if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0)printf("%d ",i);
        }
        printf("\n");
    }
    else if(N>1 && N<=7){
        switch(N){
        case 2:printf("2\n");break;
        case 3:
        case 4:printf("2 3\n");break;
        case 5:
        case 6:printf("2 3 5\n");break;
        case 7:printf("2 3 5 7\n");break;
        default:;
    }
    }
    return 0;
}

#include <stdio.h>

int main()
{
	int i,j,n;
	int a[200];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=i+1;
	for(i=1;i<n;i++)
	{
		if(a[i]==0)
			continue;
		for(j=i+1;j<n;j++)
			if(a[j]%a[i]==0)
				a[j]=0;
	}
	for(j=1;j<n;j++)//j从1开始，去除a[0](其值为1)
		if(a[j]!=0)
			printf("%d ",a[j]);
	printf("\n");
	return 0;
}*/