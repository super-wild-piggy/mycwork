#include <stdio.h>
void play(int i,int board[][3]){
    int k,l;
    for(k=0;k<i;k++){
        for(l=0;l<i;l++){
            printf("请输入在第%d行第%d列下的棋子（圈圈用1表示叉叉用0表示）\n",k+1,l+1);
            int player;
            scanf("%d",&player);
            board[k][l]=player;

        }
    }
    printf("输入完成\n");

    
}
void check(int broad[][3]){
    int i,j;
    int ret=0;
    for(i=0;i<3;i++){//检查行
        if(broad[i][0]==broad[i][1]&&broad[i][1]==broad[i][2]){
            if(broad[i][0]==0){
                ret=1;
            }else{
                ret=2;
            }
            goto out;
            
        }
    }
    for(j=0;j<3;j++){//检查列
        if(broad[0][j]==broad[1][j]&&broad[1][j]==broad[2][j]){
            if(broad[0][j]==0){
                ret=1;
            }else{
                ret=2;
            }
            goto out;
            
        }
    }
    if(broad[0][2] == broad[1][1] && broad[1][1] == broad[2][0]) {
        if(broad[0][2] == 0) {
            ret = 1;
        } else if(broad[0][2] == 1) {  // 添加条件判断
            ret = 2;
        }
        goto out;
    }
    if(broad[0][0]==broad[1][1]&&broad[1][1]==broad[2][2]){//检查对角线
        if(broad[0][0]==0){
                ret=1;
            }else{
                ret=2;
            }
    }
    out:
    if(ret==1){
        printf("Game Over Wrong wins\n");
    }else if(ret==2){
        printf("Game Over Circle wins\n");
    }
    else {
        printf("Nobody wins\n");
    }
    
    
}

int main(){
    int broad[3][3];
    int i,j;
    int count=0;
    play(3,broad);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d",broad[i][j]);
            count++;
            if(count%3==0){
                printf("\n");

            }else{
                printf(" ");
            }
        }
    }
    check(broad);
    return 0;



}