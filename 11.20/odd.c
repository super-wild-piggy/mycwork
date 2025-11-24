#include <stdio.h>

int main(){
    int n;
    printf("请输入奇数n的值\n");
    scanf("%d",&n);
    int square[n][n];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            square[i][j]=0;
        }
    }
    square[0][(n+1)/2-1]=1;
    int r0=1,c0=(n+1)/2;
    int r1,c1;
    for(i=2;i<=n*n;i++){
        if(r0==1&&c0!=n){
            r1=n;
            c1=c0+1;
        }else if(r0!=1&&c0==n){
            r1=r0-1;
            c1=1;
        }else if(r0==1&&c0==n){
            r1=r0+1;
            c1=c0;
        }else{
            r1=r0-1;
            c1=c0+1;
        }
        if(square[r1-1][c1-1]==0){
            square[r1-1][c1-1]=i;
        }else{
            r1=r0+1;
            c1=c0;
            square[r1-1][c1-1]=i;
        }
        r0=r1;
        c0=c1;
    }
    int count=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%2d",square[i][j]);
            count++;
            if(count%n==0){
                printf("\n");
            }else{
                printf("  ");
            }
        }
    }
    return 0;
}

/*第一次报错
忘记数组是从0开始索引的没有减1
第二次报错
需要变量储存原来的行数和列数*/