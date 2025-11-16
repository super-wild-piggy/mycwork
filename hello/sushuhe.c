#include <stdio.h>

int main()
{
    int m,n,j,i,num;
    int k=0;
    int sum=0;
    int count=0;
    printf("请输入区间的两个范围（正整数）\n");
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }else{
                k++;
            }

        }if(k==i-2){
            count++;
            sum+=i;
        }k=0;
    }
    printf("%d %d",count,sum);
return 0;}