#include <stdio.h>

int main()
{
    int a=1092;
   int b;
    printf("请猜数字吧，输一个数字试试看！\n");
    scanf("%d",&b);
    do{
    if (a<b){
        printf("太大了换一个试试\n");
        scanf("%d",&b);
    }else if(a>b){
        printf("太小了换一个试试\n");
        scanf("%d",&b);
    }else{
        printf("恭喜你猜对了");
    }
}while(a!=b);
    return 0;
}