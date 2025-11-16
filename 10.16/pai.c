#include <stdio.h>
#define PI 3.1415926

int main()
{
    const double PAI=3.1415926;
    float r;
    scanf("%f",&r);
    printf("圆的周长为：%f\n",2*PI*r);//用符号常量计算同下行
    printf("圆的面积为：%f\n",PI*r*r);
    printf("圆的周长为：%f\n",2*PAI*r);//用const常量计算同下行
    printf("圆的面积为：%f\n",PAI*r*r);
    return 0;


}   