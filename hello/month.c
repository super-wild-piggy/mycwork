#include <stdio.h>

int main(){
    char name[][12]={"January","February","March","April","May","June","July","August","September","October","Nomvember","December"};
    int month;
    printf("请输入你要的月份(数字)\n");
    scanf("%d",&month);
    printf("%s",name[month-1]);
    return 0;
}