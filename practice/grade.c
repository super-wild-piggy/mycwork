#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    if(n>=10){
        printf("Please input 1-9.");
    }else{
        char id[n][10];
        char name[n][10]; 
        int math[n];
        int english[n];
        int chinese[n];
        for(int i=0;i<n;i++){
            scanf("%s %s %d %d %d",id[i],name[i],&math[i],&english[i],&chinese[i]);
        }
        int order[n];
        for(int i=0;i<n;i++){
            order[i]=i;
        }
        int t;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-i;j++){
                if(math[order[j]]+chinese[order[j]]+english[order[j]]<math[order[j+1]]+chinese[order[j+1]]+english[order[j+1]]){
                    t=order[j];
                    order[j]=order[j+1];
                    order[j+1]=t;
                }else if(math[order[j]]+chinese[order[j]]+english[order[j]]==math[order[j+1]]+chinese[order[j+1]]+english[order[j+1]]){
                    if(strcmp(id[order[j]],id[order[j+1]])>0){
                        t=order[j];
                        order[j]=order[j+1];
                        order[j+1]=t;
                    }
                }
            }
        }
       
        int orderPrint[n];
        for(int i=0;i<n;i++){
            orderPrint[i]=i+1;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n-1;j++){
                if(math[order[j]]+chinese[order[j]]+english[order[j]]==math[order[j+1]]+chinese[order[j+1]]+english[order[j+1]]){
                    orderPrint[j+1]=orderPrint[j];
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%4d",orderPrint[i]);
            printf("%10s",id[order[i]]);
            printf("%10s",name[order[i]]);
            printf("%5d",math[order[i]]);
            printf("%5d",english[order[i]]);
            printf("%5d",chinese[order[i]]);
            printf("\n");
        }
    }
    return 0;
}

/*对数组进行排序 需要用到order数组用来记录顺序
循环中也使用order数组
也可以使用结构体 超级简单
因为结构体之间可以相互赋值*/