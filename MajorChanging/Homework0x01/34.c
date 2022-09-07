/*问题描述

有5个学生，每个学生有3门课的成绩，从键盘输入以上数据（包括学生号、姓名、三门课成绩），计算出平均成绩，将原有数据和计算出的平均分数存放在磁盘文件stud.dat中。然后从stud.dat文件中读出每个学生信息显示出来，包括（学生号、姓名、三门课成绩、平均成绩）。

输入形式

输入五行，只包括5个学生的数据信息。

输出形式

输出五行，给出每个学生的信息，包括学生号、姓名、三门课成绩、平均成绩。每行数据输出的格式为"%s %s %d %d %d %.2f\n"

样例输入

001 zhang 70 80 90
002 li 89 90 100
003 zhe 60 70 80
004 lei 80 90 100
005 fei 65 75 85

样例输出

001 zhang 70 80 90 80.00
002 li 89 90 100 93.00
003 zhe 60 70 80 70.00
004 lei 80 90 100 90.00
005 fei 65 75 85 75.00

*/
#include<stdio.h>
#define N 5
struct Student{
    char SN[5];
    char Name[5];
    int C1;
    int C2;
    int C3;
};
int main(){
    int i;
    double avg[N];
    struct Student student[N];
    FILE * file = fopen("stud.dat","w");
    if(file == NULL)return 0;
    for(i=0;i<N;i++){
        scanf("%s%s%d%d%d",student[i].SN,student[i].Name,&student[i].C1,&student[i].C2,&student[i].C3);
        avg[i] = (student[i].C1 + student[i].C2 + student[i].C3) / 3.0;
    }
    for(i=0;i<N;i++){
        fread(&student[i],sizeof(struct Student),1,file);
        printf("%s %s %d %d %d %.2f\n",student[i].SN,student[i].Name,student[i].C1,student[i].C2,student[i].C3,avg[i]);
    }
    fclose(file);
    return 0;
}