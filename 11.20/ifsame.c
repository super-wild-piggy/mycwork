#include <stdio.h>
#include <string.h>

int main(){
    char a[100],b[100];
    printf("请分别输入两个单词 我将帮你判断他们是不是同构的\n");
    printf("请输入第一个单词\n");
    scanf("%s",a);
    printf("请输入第二个单词\n");
    scanf("%s",b);
    int ret1=0;
    if(strlen(a)==strlen(b)){
        ret1=1;
    }
    int ret2=1;
    int i,j;
    for(i=0;i<strlen(a);i++){
        for(j=i+1;j<strlen(a);j++){
            if(a[i]==a[j]){
                if(b[i]!=b[j]){
                    ret2=0;
                    break;
                }
            }else if(a[i]!=a[j]){
                if(b[i]==b[j]){
                    ret2=0;
                    break;
                }
            }
        }
        if(ret2==0){
            break;
        }
    }
    if(ret1&&ret2){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*第一次报错 当我输入两个长度相同但是并不同构的单词时 仍给出“yes”
原因是我ret2的判断逻辑有问题 只要有一个相同ret2就会等于1

修改 原先我自己写的代码有如下几个问题
1、gets函数不安全可能会导致溢出
2、在ret2=0后没有及时结束程序
3、我在修改过程中增加的break只能跳出内层循环 外层循环没有结束


我学会了
1、break是只能跳出该层循环 continue只能跳出循环的其中一步
2、可以通过标记值让程序提前结束 只要有一个条件不满足 标记值就记为0 退出循环*/