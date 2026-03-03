#include <stdio.h>

int main(){
    char n[1001];
    scanf("%s",n);
    int time[10];
    for(int i=0;i<10;i++){
        time[i]=0;
    }
    for(int i=0;n[i]!='\0';i++){
        int count=n[i]-'0';
        time[count]++;
    }
    for(int i=0;i<10;i++){
        if(time[i]!=0){
            printf("%d:%d\n",i,time[i]);
        }
    }
    return 0;
}