#include <stdio.h>

void swapFive(int *p){
    int t,i;
    for(i=0;i<5;i++){
        t=*p;
        *p=*(p+5);
        *(p+5)=t;
        p+=1;
    }
}

int main(){
    int a[10];
    int i;
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    int *p=a;
    swapFive(p);
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}