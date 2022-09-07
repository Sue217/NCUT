/*
【问题描述】
某班有N(N<=30)个学生，共开设5门课程，分别用三个函数实现如下功能：
⑴ 求第一门课程的平均分；
⑵ 找出有2门及2门以上不及格的学生，并输出其学号；
⑶ 找出平均成绩在90分及以上的学生，输出他们的学号。
【输入形式】
第一行为一个整数N，表示本班共N个人，接下来的N行中每行包含一个学生的信息
包括学号(长度小于11的字符串)、课程1成绩、课程2成绩、课程3成绩、课程4成绩、课程5成绩。成绩均为整数
【输出形式】输出共三行：
第一行为本班第一门课程的平均成绩。(保留小数点后两位)
第二行为有2门及2门以上不及格的学生的学号，各学号之间用一个空格分隔。若不存在，则打印"no"
第三行为平均成绩在90分及以上的学生的学号, 各学号之间用一个空格分隔。若不存在，则打印"no"
【样例输入】
3
070001 90 80 85 50 42
070002 93 95 90 88 92
070003 98 92 84 90 91
【样例输出】
93.67
070001
070002 070003
【样例说明】
本班有3个学生
第1个学生学号为: 070001, 5门课程的成绩分别为: 90、80、85、50、42;
第2个学生学号为: 070002, 5门课程的成绩分别为: 93、95、90、88、92;
第3个学生学号为: 070003, 5门课程的成绩分别为: 98、92、84、90、91;
本班第1门课程的平均成绩为: 93.67; 有2门及2门以上不及格的学生的学号为: 070001;
平均成绩在90分及以上的学生的学号为: 070002、070003
*/
#include<stdio.h>
#define N 5
int flag1 = 0,flag2 = 0;
double Avg_1(int cp1[],int m){
    double avg,sum = 0;
    int i;
    for(i=0;i<m;i++)sum += cp1[i];
    avg = sum / m;
    return avg;
}
void IfPass(char * num,int point[]){
    int i,count = 0;
    for(i=0;i<N;i++){
        if(point[i] < 60)count++;
    }
    if(count >= 2){
        printf("%s ",num);
        flag1 = 1;
    }
}
void More_9(char * num,int point[]){
    int i,sum = 0;
    double avg = 0;
    for(i=0;i<N;i++)sum += point[i];
    avg = (double) sum / N;
    if(avg >= 90){
        printf("%s ",num);
        flag2 = 1;
    }
}
struct Student{
    char num[11];
    int C[N];
};
int main(){
    struct Student student[30];
    int i,j,n,cp1[30];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",student[i].num);
        for(j=0;j<N;j++){
            scanf("%d",&student[i].C[j]);
            cp1[i] = student[i].C[0];
        }
    }
    //(1)
    printf("%.2lf\n",Avg_1(cp1,n));
    //(2)
    for(i=0;i<n;i++)IfPass(student[i].num,student[i].C);
    if(flag1 == 0)printf("no");
    printf("\n");
    //(3)
    for(i=0;i<n;i++)More_9(student[i].num,student[i].C);
    if(flag2 == 0)printf("no");
    printf("\n");
    return 0;
} 