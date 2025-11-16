#include <stdio.h>

int main()
{
    int num,a,b,c;
    printf("请输入一个3位数");
    scanf("%d",&num);
    a=num%10%10;
    b=(num%100-a)/10;
    c=(num-10*b-a)/100;
    printf("%d\n",a+b+c);
    return 0;
}