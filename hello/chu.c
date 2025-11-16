#include <stdio.h>

int main()
{
    int a,b,i,ret;
    printf("请输入两个整数，我来帮你求公约数！\n");
    scanf("%d %d",&a,&b);
    //从2（i）开始一直除ab （都要整除）把最大的记下来ret 
    for(i=1;i<=a&&i<=b;i++){
        if(a%i==0&&b%i==0){
        ret=i;
        }
    }
//还有一种方法叫交替相除法 是高等代数里的内容
    printf("%d和%d的最大公约数为%d\n",a,b,ret);
    return 0;
}