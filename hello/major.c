#include <stdio.h>

int main()
{
    int grade;
    char level;
    printf("请输入你的成绩：");
    scanf("%d",&grade);
    if (grade>=90){
        level='A';
     }
         else if (grade>=80){
        level='B';
         }
           else if (grade>=70){
        level='C';
           }
        else if (grade>=60){
        level='D';
        }
        else {
            level='E';
        }
        printf("你的成绩等级为%c\n",level);

        return 0;
}