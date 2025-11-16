#include <stdio.h>

int main()
{
    int count=0;
    int n,time,num;
    scanf("%d %d",&n,&time);
    printf("\n");
    for(count=1;count<=time;count++){
        scanf("%d",&num);
        if(num<0){
            printf("Game Over");
            break;
        }
        if(num==n&&count<=3&&count!=1){
            printf("Lucky You!\n");
        }else if(num==n&&count>3&&count<=time){
            printf("Good Guess!\n");
        }else if(num==n&&count==1){
            printf("Bingo!\n");
        }else if(num!=n&&count<=time){
            if(num<n){
                printf("Too small\n");
            }else{
                printf("Too big\n");
            }
        }else{
            printf("Game Over\n");
        }
            
        }return 0;
    }
    
    
