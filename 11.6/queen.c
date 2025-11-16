#include <stdio.h>

int ifsameline(int r1,int s1,int r2,int s2){
    int i;
    int ret=1;
    for(i=1;i<8;i++){
        if((r1+i==r2&&s1+i==s2)||(r1+i==r2&&s1-i==s2)||(r1-i==r2&&s1+i==s2)||(r1-i==r2&&s1-i==s2)){
            ret=0;
            break;
        }
    }
    return ret;
}

int ifstay(int r1,int s1,int r2,int s2){
    int ret=0;
    if(r1!=r2&&s1!=s2&&ifsameline(r1,s1,r2,s2)){
        ret=1;
    }
    return ret;
}

void printbroad(int broad[8][8],int j1,int j2,int j3,int j4,int j5,int j6,int j7,int j8){
    broad[0][j1-1]=1;
    broad[1][j2-1]=1;
    broad[2][j3-1]=1;
    broad[3][j4-1]=1;
    broad[4][j5-1]=1;
    broad[5][j6-1]=1;
    broad[6][j7-1]=1;
    broad[7][j8-1]=1;
    int i,j;
    for(i=0;i<8;i++){
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*       *       *       *       *       *       *       *       *\n");
        for(j=0;j<8;j++){
            if(broad[i][j]==0){
                printf("*       ");
            }else{
                printf("*   *   ");
            }
        }
        printf("*\n");
        printf("*       *       *       *       *       *       *       *       *\n");
    }
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n\n"); 
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            broad[i][j]=0;
        }
    }
}

int main(){
    int broad[8][8];
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            broad[i][j]=0;
        }
    }
    int count=0;
    int j1,j2,j3,j4,j5,j6,j7,j8;
    for(j1=1;j1<9;j1++){
        for(j2=1;j2<9;j2++){
            if(ifstay(1,j1,2,j2)){
                for(j3=1;j3<9;j3++){
                    if(ifstay(1,j1,3,j3)&&ifstay(2,j2,3,j3)){
                        for(j4=1;j4<9;j4++){
                            if(ifstay(1,j1,4,j4)&&ifstay(2,j2,4,j4)&&ifstay(3,j3,4,j4)){
                                for(j5=1;j5<9;j5++){
                                    if(ifstay(1,j1,5,j5)&&ifstay(2,j2,5,j5)&&ifstay(3,j3,5,j5)&&ifstay(4,j4,5,j5)){
                                        for(j6=1;j6<9;j6++){
                                            if(ifstay(1,j1,6,j6)&&ifstay(2,j2,6,j6)&&ifstay(3,j3,6,j6)&&ifstay(4,j4,6,j6)&&ifstay(5,j5,6,j6)){
                                                for(j7=1;j7<9;j7++){
                                                    if(ifstay(1,j1,7,j7)&&ifstay(2,j2,7,j7)&&ifstay(3,j3,7,j7)&&ifstay(4,j4,7,j7)&&ifstay(5,j5,7,j7)&&ifstay(6,j6,7,j7)){
                                                        for(j8=1;j8<9;j8++){
                                                            if(ifstay(1,j1,8,j8)&&ifstay(2,j2,8,j8)&&ifstay(3,j3,8,j8)&&ifstay(4,j4,8,j8)&&ifstay(5,j5,8,j8)&&ifstay(6,j6,8,j8)&&ifstay(7,j7,8,j8)){
                                                                count++;
                                                                printbroad(broad,j1,j2,j3,j4,j5,j6,j7,j8);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        
                        }
                    }
               
                }
           
            }
        }
    }
    printf("一共有%d种情况",count);
    return 0;
}