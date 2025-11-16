#include <stdio.h>

int main(){
    int n;
    printf("请输入数组的长度\n");
    scanf("%d",&n);
    int i,j,k,l;
    int number[n];
    for(i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    int v=1;
    for(i=0;i<n;i++){
        v*=2;
    }
    int sum[v];
    for(i=0;i<v;i++){
        sum[i]=0;
    }
    i=0;
        for(j=1;j<=n;j++){//长度逐渐增加
            for(k=0;k+j<n;k++){//取原来的数组进行求和
                for(l=k;l<=k+j;l++){
                    sum[i]+=number[l];
                }
                i++;
            }
        }
    
    int t;
    for(i=1;i<v;i++){
        if(sum[0]<sum[i]){
            t=sum[0];
            sum[0]=sum[i];
            sum[i]=t;
        }
    }
    printf("%d",sum[0]);
}