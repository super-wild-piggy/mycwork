#include <stdio.h>

int main()
{
    int n;
    int i=1;
    double sum=0;
    printf("请输入这个数列一共有几项：\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=1.0/i;
        printf("%f\n",sum);
    }
    return 0;
}  