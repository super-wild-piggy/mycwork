#include <stdio.h>

int main(){
    int a[10];
    int min,max;
    printf("Input 10 integers:");
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    min=a[0],max=a[0];
    int minPosition=0,maxPosition=0;
    for(int i=1;i<10;i++){
        if(a[i]>max){
            max=a[i];
            maxPosition=i;
        }
        if(a[i]<min){
            min=a[i];
            minPosition=i;
        }
    }
    int t;
    t=a[minPosition];
    a[minPosition]=a[maxPosition];
    a[maxPosition]=t;
    for(int i=0;i<10;i++){
        printf("%4d",a[i]);
    }
    return 0;
}