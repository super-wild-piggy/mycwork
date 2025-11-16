#include <stdio.h>

int main()
{
    double height,weight,bmi;
    printf("请输入你的身高和体重(单位：m kg)\n");
    scanf("%lf %lf",&height,&weight);
    bmi=weight/(height*height);
    printf("%.1f\n",bmi);
    if(bmi<18.5){
        printf("Underweight\n");
    }else if(bmi>=18.5&&bmi<23.9){
        printf("Normal\n");
    }else if(bmi>=23.9&&bmi<=27.9){
        printf("Overweight\n");
    }else{
        printf("Obese\n");
    }
    return 0;
}
