#include <stdio.h>

int main()
{
    int grade;
    char level;
    int a,b;//a为十位数 b为个位数
    printf("请输入你的成绩\n");
    scanf("%d",&grade);
    a=grade/10;
    b=grade%10;
    switch(a){
        case 10:
        level='A';
        break;
        case 9:
        switch(b){
            case 1:
            case 2:
            case 3:
            case 4:
            level='B';
            break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            level='A';
            break;
        }
        break;
        case 8:
        level='B';
        break;
        case 7:
        level='C';
        break;
        case 6:
        level='C';
        break;
        default:
        level='D';
    }printf("你的等级为%c",level);
    return 0;
}