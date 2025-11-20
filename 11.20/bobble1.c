#include <stdio.h>

int search(int number[],int low,int high,int target){
    int m=low+(high-low)/2;
    if(number[m]==target){
        return m;
    }else if(number[m]<target){
        return search(number,m+1,high,target);
    }else{
        return search(number,low,m-1,target);
    }
}

int main(){
    int n;
    int i,j;
    printf("请输入你要输入几个整数\n");
    scanf("%d",&n);
    int number[n];
    for(i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    int t;
    int count=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(number[j]>number[j+1]){
                t=number[j];
                number[j]=number[j+1];
                number[j+1]=t;
                count=1;
            }
        }
        if(!count){
            break;
        }else{
            count=0;
        }
    }
    int target;
    printf("请输入你要查找的数字\n");
    scanf("%d",&target);
    printf("你找的数字在第%d的位置上\n",search(number,0,n-1,target)+1);
    return 0;
}