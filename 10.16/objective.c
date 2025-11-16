#include <stdio.h>

int main()
{
    int a;
    printf("请输入一个整数:\n");
    scanf("%d",&a);
    if(a%2==0){
        printf("%d这个数字是偶数\n",a);
    }else{
        printf("%d这个数字是奇数\n",a);
    }return 0;
}