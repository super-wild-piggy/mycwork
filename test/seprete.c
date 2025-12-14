#include <stdio.h>

int isPrime(long x){
    int ret=1;
    for(int i=2;i<=x/2;i++){
        if(x%i==0){
            ret=0;
            break;
        }
    }
    return ret;
}

void getPrimePair(long m){
    int count=0;//拆解的次数
    for(long i=1;i<=m/2;i++){
        if(isPrime(i)){
            if(isPrime(m-i)){
                printf("%ld=%ld+%ld\n\n",m,i,m-i);
                count++;
            }
        }
    }
    printf("The number %d has %d prime number decomposition methods\n",m,count);

}

int main(){
    long m;
    scanf("%d",&m);
    if(m<=4||m%2!=0){
        printf("The end\n");
    }else{
        getPrimePair(m);
    }
    return 0;
}