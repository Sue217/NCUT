/*
【问题描述】在一个有200人的大班级中，存在两个人生日相同的概率非常大，现给出每个学生的学号，出生月日，试找出所有生日相同的学生。
【输入形式】第一行为整数n，表示有n个学生，n<=200。此后每行包含一个字符串和两个整数，分别表示学生的学号(字符串长度为11位)和出生月(1<=m<=12)日(1<=d<=31)，学号、月、日之间用一个空格分隔。
【输出形式】对每组生日相同的学生，输出一行，其中前两个数字表示月和日，后面跟着所有在当天出生的学生的学号，数字、学号之间都用一个空格分隔。对所有的输出，要求按日期从前到后的顺序输出。对生日相同的学号，按输入的顺序输出。
【样例输入】
    6
    07101020105 3 15
    07101020115 4 5
    07101020118 3 15
    07101020108 4 5
    07101020111 4 5
    07101020121 8 10
【样例输出】
    3 15 07101020105 07101020118
    4 5 07101020115 07101020108 07101020111
    8 10 07101020121
*/
#include <stdio.h>
struct Student{
    char num[12];
    int mon;
    int day;
};
struct obj{
    int mon;
    int day;
    int count;
};
int main(){
    struct Student student[200],tmp;
    struct obj con[200];
    int i,j,k,w,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s%d%d",student[i].num,&student[i].mon,&student[i].day);
    //sort birthday
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(student[j].mon > student[j+1].mon){
                tmp = student[j];
                student[j] = student[j+1];
                student[j+1] = tmp;
            }
            else if(student[j].mon == student[j+1].mon){
                if(student[j].day > student[j+1].day){
                    tmp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = tmp;
                }
            }
        }
    }
    //copy
    for(i=0;i<n;i++){
        con[i].mon = student[i].mon;
        con[i].day = student[i].day;
        con[i].count = 1;
    }
    //count
    for(i=1,j=0;i<n;i++){
        if(student[i].mon==con[j].mon && student[i].day==con[j].day)con[j].count++;
        else{
            j++;
            con[j].mon = student[i].mon;
            con[j].day = student[i].day;
        }
    }
    for(k=0,w=0;k<=j;k++){
        printf("%d %d ",con[k].mon,con[k].day);
        for(i=0;i<con[k].count;i++,w++)printf("%s ",student[w].num);
        printf("\n");
    }
    return 0;
}