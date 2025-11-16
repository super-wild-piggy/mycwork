#include <stdio.h>

int main()
{
    int n=1;
    int x;
    printf("请输入一个数字：");
    scanf("%d",&x);
    x=x/10;
    while(x>0){
        n=n+1;
        x=x/10;
    }
    printf("这个数是%d位数\n",n);
    return 0;
}