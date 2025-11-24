#include <stdio.h>

int main(){
    int n,m,k;
    printf("请输入士兵的个数\n");
    scanf("%d",&n);
    printf("请输入从哪一个编号开始\n");
    scanf("%d",&k);
    printf("请输入每一次数几个士兵\n");
    scanf("%d",&m);
    int people[n];
    int i;
    for (i=0;i<n;i++){
        people[i]=i+1;
    }
    int position=k-1;
    while(n!=1){
        if((position+m)%n!=0){
            printf("出列的士兵编号为%d\n",people[(position+m)%n-1]);
            for(i=(position+m)%n-1;i<n-1;i++){
                people[i]=people[i+1];
            }
            position=(position+m)%n-1;
            people[n-1]=-1;
            n--;
        }else{
            printf("出列的士兵编号为%d\n",people[n-1]);
            people[n-1]=-1;
            position=0;
            n--;
        }
    }
    printf("仅存的士兵编号为%d\n",people[0]);
    return 0;
}

/*这次作业我经过了多次调试才得出了正确结果
第一次报错由于我没有考虑当取余得0的情况导致数组越界
第二次报错是n--出现的位置有问题
我发现像这样注重逻辑的题目我需要用一个草稿纸试验一些例子
还最好是特例*/