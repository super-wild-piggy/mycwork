#include <stdio.h>
void maxmin(int *max,int *min,int number[],int length);

int main(){
    int number[]={1,2,3,4,5,6,7,8,9,0};
    int max,min;
    maxmin(&max,&min,number,sizeof(number)/sizeof(number[0]));
    printf("min=%d,max=%d\n",min,max);
}

void maxmin(int *max,int *min,int number[],int length){
    int i;
    *max=number[0];
    *min=number[0];
    for(i=1;i<length;i++){
        if(*min>number[i]){
            *min=number[i];
        
        }
        if(*max<number[i]){
            *max=number[i];
        }
    }
}