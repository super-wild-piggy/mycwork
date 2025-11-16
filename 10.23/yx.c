#include <stdio.h>

int main()
{
    double x,y;
    printf("请输入你需要的x\n");
    scanf("%lf",&x);
    if(x<-1){
        y=-1*x;
    }else if(x>1){
        y=2*x+1;
    }else{
        y=x*x;
    }
    printf("y=%.2f",y);
    return 0;
}