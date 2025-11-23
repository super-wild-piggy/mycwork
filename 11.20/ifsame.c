#include <stdio.h>
#include <string.h>

int main(){
    char a[100],b[100];
    printf("请分别输入两个单词 我将帮你判断他们是不是同构的\n");
    printf("请输入第一个单词\n");
    gets(a);
    printf("请输入第二个单词\n");
    gets(b);
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
                }
            }else if(a[i]!=a[j]){
                if(b[i]==b[j]){
                    ret2=0;
                }
            }
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
原因是我ret2的判断逻辑有问题 只要有一个相同ret2就会等于1*/