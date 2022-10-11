//输入一行字符，统计出其中英文字母、数字、空格和其他字符的个数
#include<stdio.h>
int main()
{
    char ch;
    int space = 0, num = 0, chara = 0, other = 0;
    printf("输入一行字符：");
    ch = getchar();
    while (ch != '\n')
    {
        if (ch == ' ')
        {
            space++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            num++;
        }
        else if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        {
            chara++;
        }
        else
        {
            other++;
        }
        ch = getchar();
    }
    printf("英文字母有%d个\n数字有%d个\n空格有%d个\n其他字符有%d个\n", chara, num, space, other);
}