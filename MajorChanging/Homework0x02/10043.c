/*
【问题描述】学生信息包括：学号、姓名、数学成绩、英语成绩、计算机成绩。
共有N个人(N<=10，可在程序内部定义，如用#define  N 3) 的信息。
要求计算每人的总成绩，并按总成绩由高到低的顺序输出所有人的信息。
最后输出各门课程平均成绩(保留2位小数)。（此题只按照3个学生考虑）
【输入形式】输入分N行，每行为一个学生的学号、姓名、数学成绩、英语成绩、计算机成绩信息。
【输出形式】输出为N+4行。
第一行为固定字符串;第2~N+1行为按总成绩由高到低顺序输出的所有人信息;
最后3行输出各门课程的平均成绩。
要求:1、输出的第一行，每个元素的后面空3个空格，Total后不加空格;
2、输出的第二行到第N+1行，每个元素后面空4个空格，最后一个元素，如258后面不加空格，且每行以回车符结束;
3、输出的最后三行没有空格，每行仅以回车符结束。
【样例输入】
1001   zhang    90    80    88
1002   huang    78     80    82
1003   xiong    88     85    80
【样例输出】
NO   Name   Maths   English   Computer   Total 
1001    zhang    90    80    88    258
1003    xiong    88     85    80    253
1002    huang    78    80    82    240
average of Maths:85.33
average of English:81.67
average of Computer:83.33 
【样例说明】实际上这个结果应该是下面的样子：
NO（3个空格）Name（3个空格） Maths（3个空格）English（3个空格）Computer（3个空格）Total
1001（4个空格）zhang（4个空格）90（4个空格）80（4个空格）88（4个空格）258
1003（4个空格）xiong（4个空格）88（4个空格）85（4个空格）80（4个空格）253
1002（4个空格）huang（4个空格）78（4个空格）80（4个空格）82（4个空格）240
average of Maths:85.33
average of English:81.67
average of Computer:83.33
*/
#include<stdio.h>
#define N 3
struct Student{
    char num[10];
    char name[7];
    int Maths;
    int English;
    int Computer;
    int Total;
};
int main(){
    struct Student student[N],tmp;
    int i,j;
    float avg1,avg2,avg3;
    avg1 = avg2 = avg3 = 0.0;
    for(i=0;i<N;i++)student[i].Total = 0;
    for(i=0;i<N;i++){
        scanf("%s%s%d%d%d",student[i].num,student[i].name,&student[i].Maths,&student[i].English,&student[i].Computer);
        student[i].Total += student[i].Maths + student[i].English + student[i].Computer;
    }
    for(i=0;i<N;i++)avg1 += student[i].Maths;
    for(i=0;i<N;i++)avg2 += student[i].English;
    for(i=0;i<N;i++)avg3 += student[i].Computer;
    avg1 /= 3.0;
    avg2 /= 3.0;
    avg3 /= 3.0;
    for(i=0;i<N;i++){
        for(j=0;j<N-i-1;j++){
            if(student[j].Total < student[j+1].Total){
                tmp = student[j];
                student[j] = student[j+1];
                student[j+1] = tmp;
            }
        }
    }
    printf("NO   Name   Maths   English   Computer   Total\n");
    for(i=0;i<N;i++)printf("%s    %s    %d    %d    %d    %d\n",student[i].num,student[i].name,student[i].Maths,student[i].English,student[i].Computer,student[i].Total);
    printf("average of Maths:%.2f\n",avg1);
    printf("average of English:%.2f\n",avg2);
    printf("average of Computer:%.2f\n",avg3);
    return 0;
}