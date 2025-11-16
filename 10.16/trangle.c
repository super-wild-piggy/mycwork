#include <stdio.h>
#include <math.h>


int main()
{
    float a,b,c;
    printf("请分别输入三角形的三条边长（中间加空格隔开）\n");
    scanf("%f %f %f",&a,&b,&c);
    if(a+b>c&&b+c>a&&a+c>b){
        float p=(a+b+c)/2;
        printf("三角形的面积为%f\n",sqrt(p*(p-a)*(p-b)*(p-c)));
    }else{
        printf("无法构建三角形！\n");
    }return 0;
    
}