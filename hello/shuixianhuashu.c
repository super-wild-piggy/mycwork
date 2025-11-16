#include <stdio.h>

int main()
{
    int n,edge,i,j,d,sum,t,k,l,p;
    edge=1;
    sum=0;
    printf("请输入你想要几位的水仙花数(3<=N<=7)\n");
    scanf("%d",&n);
    for(k=1;k<n;k++){
        edge*=10;
    }
    for(i=edge;i<edge*10;i++){
        t=i;
        for(l=1;l<=n;l++){
            d=t%10;
            p=d;
            t/=10;
            for(j=1;j<=n-1;j++){
                d*=p;
            }
            sum+=d;
          
            } if(sum==i){
                printf("%d\n",sum);
                sum=0;
            
        }else{
            sum=0;
        } 
    }
}