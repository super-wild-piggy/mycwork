#include <stdio.h>

int ifright(int position[8]);
int main(){
    char putin[9];
    int position[8];
    int count[8]={0};
    scanf("%s",putin);
    int i,answer,place;
    for(i=0;i<8;i++){
       if(putin[i]>='1'&&putin[i]<='8'){
            position[i]=putin[i]-'1'+1;
            count[position[i]-1]=1;
       }else if(putin[i]=='*'){
            place=i;
            position[i]=0;
       }
    }
    for(i=0;i<8;i++){
        if(count[i]==0){
            position[place]=i+1;
            break;
        }
    }
    if(ifright(position)){
        printf("%d\n",position[place]);
    }else{
        printf("No Answer");
    }
    return 0;
}

int ifright(int position[8]){
    int ret=1;
    int i,j;
    for(i=0;i<8;i++){
        for(j=i+1;j<8;j++){
            if(position[i]-position[j]==i-j||position[i]-position[j]==j-i){
                ret=0;
            }
        }
    }
    return ret;
}