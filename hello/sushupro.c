#include <stdio.h>
void enter(int,int[]);
int main()
{
    int prime[100];
    int count=0;
    int i=3;
    prime[0]=2;
    for(i=3;count<99;i++){
        int j;
        int ret=1;
        for(j=0;j<=count;j++){
            if(i%prime[j]==0){
                ret=0;
                break;
            }
        }if(ret==1){
            count++;
            prime[count]=i;
        }
    }
    enter(count,prime);
    
    return 0;}


void enter(int count,int prime[]){
    int i;
    for(i=0;i<=count;i++){
        printf("%d",prime[i]);
        if((i+1)%5==0){
            printf("\n");
        }else{
            printf(" ");
        }
}
}