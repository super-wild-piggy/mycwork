#include <stdio.h>

int main()
{
    int x,d;
    int mask=1;
    
    printf("请输入一个正整数：\n");
    scanf("%d",&x);
    int t=x;
    while(t>9){
        mask*=10;
        t/=10;
    }printf("%d\n",mask);
    while(mask>0){
        d=x/mask;
       printf("%d ",d);
        x=x%mask; 
        mask/=10;
    }
    return 0;

}