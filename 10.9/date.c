#include <stdio.h>

int main()
{
    printf("请分别输入年月日：");
    int year,month,day,sum,month2;
    scanf("%d %d %d",&year,&month,&day);
     if ((year%4==0&&year%100!=0)||(year%400==0)){
     month2=29;
       }else{
        month2=28;
       }
    switch(month){
        case 1:
        sum=day;
        break;
        case 2:
        sum=31+day;
        break;
        case 3:
        sum=31+month2+day;
        break;
        case 4:
        sum=62+month2+day;
        break;
        case 5:
        sum=92+month2+day;
        break;
        case 6:
        sum=123+month2+day;
        break;
        case 7:
        sum=153+month2+day;
        break;
        case 8:
        sum=184+month2+day;
        break;
        case 9:
        sum=215+month2+day;
        break;
        case 10:
        sum=245+month2+day;
        break;
        case 11:
        sum=276+month2+day;
        break;
        case 12:
        sum=306+month2+day;
        break;
    }
printf("这是当年的第%d天\n",sum);
return 0;
}