#include <stdio.h>

int main(){
    int month;
    printf("请输入月份\n");
    scanf("%d",&month);
    int i1=1;
    int i2=1;
    int i;
    int n=1;
    if(month==1||month==2){
        n=1;
    }else{
        for(i=3;i<=month;i++){
            int t; 
            n=i1+i2;
            t=i2;
            i2=i1+i2;
            i1=t;
           
        }
    }
    printf("%d",n);
    return 0;
}