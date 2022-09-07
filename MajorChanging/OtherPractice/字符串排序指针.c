/*
题目描述
安全局搜索到了一批(n个)身份证号码，希望按出生日期对它们进行从大到小排序，如果有相同日期，则按身份证号码大小进行排序。
身份证号码为18位的数字组成，出生日期为第7到第14位

输入
第一行一个整数n，表示有n个身份证号码 
余下的n行，每行一个身份证号码。 
数据规模和约定
n< =100000

输出
按出生日期从大到小排序后的身份证号，每行一条

样例输入
5 
466272307503271156 
215856472207097978 
234804580401078365 
404475727700034980 
710351408803093165 
样例输出
404475727700034980
234804580401078365
215856472207097978
710351408803093165
466272307503271156
*/
#include<stdio.h>
#include<string.h>
char str[10000][20],tmp[20],ch[10000][9];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)scanf("%s",str[i]);
    for(i=0;i<n;i++){
        for(k=0,j=6;j<14;j++,k++){
            ch[i][k] = str[i][j];
        }
        ch[i][k] = '\0';
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(*(ch+j),*(ch+j+1)) < 0){
                strcpy(tmp,*(str+j));
                strcpy(*(str+j),*(str+j+1));
                strcpy(*(str+j+1),tmp);
                strcpy(tmp,*(ch+j));
                strcpy(*(ch+j),*(ch+j+1));
                strcpy(*(ch+j+1),tmp);
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)printf("%s\n",str[i]);
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
int main(){
    int i,j,k,n;
    char num[100001][19],* p[100001],* q[100001],* tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        q[i] = num[i];
        p[i] = *(num+i) + 6;//
        scanf("%s",num[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(p[j],p[j+1]) < 0){
                tmp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = tmp;
                tmp = *(q+j);
                *(q+j) = *(q+j+1);
                *(q+j+1) = tmp;
            }
        }
    }
    for(i=0;i<n;i++)printf("%s\n",q[i]);
    return 0;
}
*/