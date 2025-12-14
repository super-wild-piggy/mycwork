#include <stdio.h>

int ifright(int position[8]);
int main(){
    char putin[9];
    int position[8];
    int count[8]={0};
    scanf("%s",putin);
    int i,answer,place;
    for(i=0;i<8;i++){
        switch(putin[i]){
            case '1':
            position[i]=1;
            count[0]=1;
            break;
            case '2':
            position[i]=2;
            count[1]=1;
            break;
            case '3':
            position[i]=3;
            count[2]=1;
            break;
            case '4':
            position[i]=4;
            count[3]=1;
            break;
            case '5':
            position[i]=5;
            count[4]=1;
            break;
            case '6':
            position[i]=6;
            count[5]=1;
            break;
            case '7':
            position[i]=7;
            count[6]=1;
            break;
            case '8':
            position[i]=8;
            count[7]=1;
            break;
            case '9':
            position[i]=9;
            count[8]=1;
            break;
            case '*':
            position[i]=0;
            place=i;//记录*的位置
            break;
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