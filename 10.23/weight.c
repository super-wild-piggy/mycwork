#include <stdio.h>

int ball[13]={0};

/*平衡输出0 左边大输出-1 右边大输出1*/

int weight(int everyside,int number[]){
    int left=0;
    int right=0;
    int i,j;
    for(i=0;i<everyside;i++){
        left+=ball[number[i]-1];
    }
    for(j=everyside;j<2*everyside;j++){
        right+=ball[number[j]-1];
    }
    if(left==right){
        return 0;
    }else if(left<right){
        return 1;
    }else if(left>right){
        return -1;
    }
}

void printret(int time,int everyside,int number[]){
    printf("第%d次对%d个球进行称重\n",time,2*everyside);
    int i,j;
    printf("左边\n");
    for(i=0;i<everyside;i++){
        printf("%d ",number[i]);
    }
    printf("\n右边\n");
    for(j=everyside;j<2*everyside;j++){
        printf("%d ",number[j]);
    }
    printf("\n");
    int ret=weight(everyside,number);
    if(ret==0){
        printf("天平平衡\n");
    }else if(ret==1){
        printf("天平向右倾斜\n");
    }else if(ret==-1){
        printf("天平向左倾斜\n");
    }
}

int main(){
    int choice,change,no;
    printf("你想改变几号球的重量\n");
    scanf("%d",&change);
    choice=0;
    int i;
    for(i=0;choice!=1&&choice!=2;i++){
        printf("请选择你要增重还是减重\n1 增重\n2 减重\n");
        scanf("%d",&choice);
        if(choice==1){
            ball[change-1]=1;
        }else if(choice==2){
            ball[change-1]=-1;
        }else{
            printf("输入无效请重新输入\n");
        }
    }
    int first[13]={1,2,3,4,5,6,7,8};
    printret(1,4,first);
    int ret1=weight(4,first);
    int ret2,ret3;
    if(ret1==0){
        int second[13]={1,2,3,9,10,11};
        printret(2,3,second);
        ret2=weight(3,second);
        if(ret2==0){
            int third[13]={12,1};
            printret(3,1,third);
            ret3=weight(2,third);
            if(ret3==0){
                no=13;
            }else{
                no=12;
            }
        }else if(ret2==-1){
            int third[13]={9,10};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==0){
                no=11;
            }else if(ret3==-1){
                no=10;
            }else{
                no=9;
            }
        }else{
            int third[13]={9,10};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==0){
                no=11;
            }else if(ret3==-1){
                no=9;
            }else{
                no=10;
            }
        }
    }else if(ret1==-1){
        int second[13]={1,2,5,3,4,6};
        printret(2,3,second);
        ret2=weight(3,second);
        if(ret2==0){
            int third[13]={7,8};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==-1){
                no=8;
            }else{
                no=7;
            }
        }else if(ret2==-1){
            int third[13]={1,2};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==0){
                no=6;
            }else if(ret3==-1){
                no=1;
            }else{
                no=2;
            }
        }else{
            int third[13]={3,4};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==0){
                no=5;
            }else if(ret3==-1){
                no=3;
            }else{
                no=4;
            }
        }
    }else{
        int second[13]={1,2,5,3,4,6};
        printret(2,3,second);
        ret2=weight(3,second);
        if(ret2==0){
            int third[13]={7,8};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==-1){
                no=7;
            }else{
                no=8;
            }
        }else if(ret2==-1){
            int third[13]={3,4};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==0){
                no=5;
            }else if(ret3==-1){
                no=4;
            }else{
                no=3;
            }
        }else{
            int third[13]={1,2};
            printret(3,1,third);
            ret3=weight(1,third);
            if(ret3==0){
                no=6;
            }else if(ret3==-1){
                no=2;
            }else{
                no=1;
            }
        }
    }
    printf("异常重量的球是%d",no);
    return 0;
}
