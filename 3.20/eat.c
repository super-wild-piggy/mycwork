#include <stdio.h>
#include <stdlib.h>

struct person{
    int time;
    int pos;
};
typedef struct person person_t;


int main(){
    int n;
    int m;
    scanf("%d %d",&n,&m);
    person_t human[n];
    for(int i=0;i<n;i++){
        scanf("%d",&human[i].time);
        human[i].pos=-1;
    }
    int window_time[m];
    for(int i=0;i<m;i++){
        window_time[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(human[j].time>human[j+1].time){
                person_t temp=human[j];
                human[j]=human[j+1];
                human[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        int min_window_idx=i%m;
        human[i].pos=min_window_idx;//把人放进窗口里
        //更新窗口时间
        for(int j=0;j<i;j++){
            if(human[j].pos==min_window_idx){
                window_time[min_window_idx]+=human[j].time;
            }
        }
    }
    int total_time=0;
    for(int i=0;i<m;i++){
        total_time+=window_time[i];
    }
    printf("%d",total_time);
    return 0;

}