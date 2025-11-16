#include <stdio.h>

int main()
{
    float tem;
    printf("请输入华氏温度：（单位：。F）\n");
    scanf("%f",&tem);
    printf("摄氏温度为：%f。C\n",(tem-32)*5/9);
    return 0;
}