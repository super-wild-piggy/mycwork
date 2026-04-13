#include <stdio.h>
#include <stdlib.h>

int main(){
    int ch;
    int *arr;
    arr=malloc(100*sizeof(int));
    if(arr==NULL){
        printf("分配失败\n");
        return 1;
    }
    int time=1;//记录分配次数
    int idx=0;
    int num=0;//用于记录读入的数字
    while((ch=getchar())!=EOF){
        if(ch>='0'&&ch<='9'){
            num=num*10+ch-'0';
        }else{
            if(idx>=time*100){
                arr=realloc(arr,100*sizeof(int));
                time++;
            }
            arr[idx]=num;
            num=0;
            idx++;
        }
    }
    idx--;
    int target=arr[idx];
    int idx1=-1; 
    int idx2=-1;
    int ret=0;
    for(int i=0;i<idx;i++){
        for(int j=i+1;j<idx;j++){
            if(arr[i]+arr[j]==target){
                idx1=i;
                idx2=j;
                ret=1;
                break;
            }
        }
        if(ret==1){
            break;
        }
    }
    printf("%d %d",idx1,idx2);
    free(arr);
    return 0;
}