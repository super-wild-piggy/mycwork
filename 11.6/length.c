#include <stdio.h>

int main(){
    int n;
    printf("请输入一个正整数n\n");
    scanf("%d",&n);
    int number[n],length;
    scanf("%d",&length);
    int i;
    int j=0;
    for(i=0;i<n;i++){
        number[n-1-i]=length%10;
        length/=10;
    }
    int count[n];
    for(i=0;i<n;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        if(number[i]==1){
            if(number[i-1]==number[i]||number[i+1]==number[i]){
                count[j]=count[j]+1;
                if(number[i+1]==0){
                    j+=1;
                }  
            }
        }
    }
    int t;
    for(i=1;i<n;i++){
        if(count[0]<count[i]){
            t=count[0];
            count[0]=count[i];
            count[i]=t;
        }
    }
    printf("%d",count[0]);
    return 0;
    }