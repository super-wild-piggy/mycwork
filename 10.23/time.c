#include <stdio.h>


void one(int x){ 
if(x/10==0){
        printf("0%d",x);
    }else{
        printf("%d",x);
    }}


int main()
{
    int h,m,s;
    printf("请分别输入小时分钟秒\n");
    scanf("%d %d %d",&h,&m,&s);
    one(h);
    printf(":");
    one(m);
    printf(":");
    one(s);
    return 0;  
}