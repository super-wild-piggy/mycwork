#include <stdio.h>

int main(){
    int n;
    printf("请输入你要输入几个数字（1<=n<=108）\n");
    scanf("%d",&n);
    int i,number[108],j,t;
    for(i=0;i<n;i++){
        printf("请输入数字\n");
        scanf("%d",&number[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(number[i]>number[j]){
                t=number[i];
                number[i]=number[j];
                number[j]=t;
            }
        }  
    }
    int count=0;
    for(i=0;i<n-1-count;i++){
        if(number[i]==number[i+1]){
            for(j=i;j<n-count;j++){
                number[j]=number[j+1];
            }
            number[n-1-count]=0;
            count++;
            i-=1;
        }
    }
    for(i=0;i<n-count;i++){
        printf("%d ",number[i]);
    }
    return 0;
}