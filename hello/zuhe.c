#include <stdio.h>

int main()
{
    int a;
    int count=0;
    printf("请输入一个正整数\n");
    scanf("%d",&a);
    int i,j,k;
    for(i=a;i<=a+3;i++){
        for(j=a;j<=a+3;j++){
            for(k=a;k<=a+3;k++){
                if(i!=j&&j!=k&&k!=i){
                    printf("%d%d%d",i,j,k);
                    count++;
                    if(count==6){
                        printf("\n");
                        count=0;
                    }else{
                        printf(" ");
                    }
                }
            }
        }
    }return 0;
}