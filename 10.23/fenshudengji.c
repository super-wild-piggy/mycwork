#include <stdio.h>

int main()
{
    int grade,x;
    char level;
    printf("请输入你的成绩\n");
    scanf("%d",&grade);
    x=grade/10;
    if(grade<0||grade>100){
        printf("输入无效\n");
    }else{
    switch (x){
        case 10:
        level='A';
        break;
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
    printf("您的成绩等级为%c\n",level);
}
return 0;
    
}