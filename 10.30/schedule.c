#include <stdio.h>
int if229(int year){
    if((year%4==0&&year%100!=0)||year%400==0){
        return 1;
    }else{
        return 0;
    }
}

int theDayOfYear(int year){
    if(if229(year)){
        return 366;
    }else{
        return 365;
    }
}

int theDayOfMonth(int month,int year){
    int day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int trueday;
    if(month==2&&if229(year)){
        trueday=29;
    }else{
        trueday=day[month-1];
    }
    return trueday;
}

int whatday(int year,int month){   //判断这个月的第一天是这年的第几天
    int i;
    int day=1;
    for(i=1;i<month;i++){
        day+=theDayOfMonth(i,year);
    }
    return day;
}

void printMonth(int month,int year){
    int totalDay,i;
    totalDay=0;
    for(i=1990;i<year;i++){
        totalDay+=theDayOfYear(i);
    }
    totalDay+=whatday(year,month);
    int n;//空格几次
    n=totalDay%7-1;
    printf("MON TUE WED THU FRI SAT SUN\n");
    for(i=0;i<n;i++){
        printf("    ");
    }
    for(i=01;i<=theDayOfMonth(month,year);i++){    
        if(i<10){
            printf("0");
        }
        printf("%d",i);
    
        if((n+i)%7==0){
            printf("\n");
        }else{
            printf("  ");
        }
    }
}

void printYear(int year){
    int i; 
    printf("          %d年\n",year);
    for(i=1;i<=12;i++){
       printf("           %d月\n",i);
       printMonth(i,year);
       printf("\n");
    }
}

int main(){
    int year,month,choice;
    printf("请做出你的选择\n1：输出月历\n2：输出年历\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("请输入年份和月份\n");
        scanf("%d年%d月",&year,&month);
        if(year<1900||(month<1&&month>12)){
            printf("输入无效\n");
        }else{
            printf("         %d年%d月\n",year,month);
            printMonth(month,year);
        }
    }
    if(choice==2){
        printf("请输入年份\n");
        scanf("%d年",&year);
        if(year<1900){
            printf("输入无效\n");
        }else{
            printYear(year);
        }
    }
}