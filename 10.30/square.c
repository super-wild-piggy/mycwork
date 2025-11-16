#include <stdio.h>

int main(){
    int n;
    printf("请输入一个整数\n");
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        printf("*");
    }
    printf("\n");
    int j;
    for(j=1;j<=n-2;j++){
        for(i=1;i<=n;i++){
            if(i==1||i==n){
                printf("*");
            }else if(n%2==1&&j==(n-2)/2+1&&i==n/2+1){
                printf("*");
            }else{
                printf(" ");
            }
        } 
       printf("\n");
    }
    for(i=1;i<=n;i++){
        printf("*");
    }
    return 0;
}