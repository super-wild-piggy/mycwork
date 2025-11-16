#include <stdio.h>

int main()      
{
    int n,j;
    int i=1;
    printf("请输入一个一位的正整数\n");
    scanf("%d",&n);
    for(j=1;j<=n;j++){
            printf("%d*%d=%d",i,j,i*j);
            if(i==j){
                printf("\n");
                i=1;
            }else{
                printf(" ");
                 if((i==2&&j==3)||(i==2&&j==4)){
                printf(" ");
                 }
                i++;
                j--;
            }
           
        }
    return 0;
}