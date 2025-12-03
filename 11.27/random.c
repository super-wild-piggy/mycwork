#include <stdio.h>
#include <stdlib.h>


int main(){
    int random_num[10];
    int i;
    srand(1);
    for(i=0;i<10;i++){
        random_num[i]=rand()%50;
    }
    for(i=0;i<10;i++){
        printf("%d",random_num[i]);
        if(i!=9){
            printf(" ");
        }
    }
    printf("\n");
    int j,t;
    for(i=0;i<10;i++){
        for(j=0;j<9-i;j++){
            if(random_num[j]>random_num[j+1]){
                t=random_num[j];
                random_num[j]=random_num[j+1];
                random_num[j+1]=t;
            }
        }
    }
    for(i=0;i<10;i++){
        printf("%d",random_num[i]);
        if(i!=9){
            printf(" ");
        }
    }
    return 0;
}

/*生成随机数函数
rand(void)
设置随机种子函数
srand(int)
随机数范围
n-s
rand()%(s+1)+n*/