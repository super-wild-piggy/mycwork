#include <stdio.h>

int main()
{
    int grade,grade1;
    char level;
    printf("请输入你的成绩：");
    scanf("%d",&grade);
    grade1=grade/10;
    switch(grade1){
    case 9:
    level='A';
    break;
    case 8:
    level='B';
    break;
    case 7:
    level='C';
    break;
    case 6:
    level='D';
    break;
    default:
    level='E';
    break;
    }
    printf("您的成绩等级为：%c\n",level);
    return 0;


}