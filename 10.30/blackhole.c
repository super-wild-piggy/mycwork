#include <stdio.h>

void maxminpro(int *max,int *middle,int *min,int a,int b,int c){
    int abc[3]={a,b,c};
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=i+1;j<3;j++){
            if(abc[i]>=abc[j]){
                k=abc[i];
                abc[i]=abc[j];
                abc[j]=k;
            }
        }
    }
    *max=abc[2];
    *middle=abc[1];
    *min=abc[0];
}

int main(){
    printf("请输入一个小于1000的整数\n");
    int n;
    scanf("%d",&n);
    while(n!=495){
        int a,b,c; //分别为百位 十位 个位
        c=n%10;
        n/=10;
        b=n%10;
        n/=10;
        a=n%10;
        int max,min,middle;
        maxminpro(&max,&middle,&min,a,b,c);
        int big,small; //big指的是重新排列后的最大数
        big=max*100+middle*10+min*1;
        small=min*100+middle*10+max*1;
        n=big-small;
        printf("%d-%d=%d\n",big,small,n);
        }
        return 0;
    }
    