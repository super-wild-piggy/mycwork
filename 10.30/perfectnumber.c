#include <stdio.h>

int main(){
    int n;
    printf("请输入一个正整数\n");
    scanf("%d",&n);
    int count=0;
    int i;
    for(i=1;n>0;i++){
        if(n<i*i){
            count++;
            n=n-(i-1)*(i-1);
            i=1;
        }
        }
    
    printf("%d",count);
    return 0;
}