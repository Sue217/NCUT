/*
 1 
 1 1 
 1 2 1 
 1 3 3 1 
 1 4 6 4 1
*/

#include<stdio.h>
int main(){
	int st[25][25];
	int i,j,n;
	st[0][0]=1;
	st[1][0]=st[1][1]=1;
	scanf("%d",&n);
	for(i=2;i<n;i++){
		st[i][0]=st[i][i]=1;
		for(j=1;j<i;j++)
			st[i][j]=st[i-1][j-1]+st[i-1][j];
	}
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			printf("%d ",st[i][j]);
		printf("\n");
	}
	return 0;
}
