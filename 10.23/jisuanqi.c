#include <stdio.h>

int main()
{
    int a,b;//计算的两个数
    printf("请输入两个整数\n");
    scanf("%d %d",&a,&b);
    printf("他们的和为%d 乘积为%d 差为%d 商为%d 余数为%d\n",a+b,a*b,a-b,a/b,a%b);
    return 0;
}