#include <stdio.h>

int main()
{
    int num,i;
    printf("请输入一个三位整数:\n");
    scanf("%d",&num);
    for(i=1;num>0;i++){
        printf("%d",num%10);
        num/=10;
    }return 0;
}