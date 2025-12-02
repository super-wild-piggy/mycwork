#include <stdio.h>

void iflegal(char *str){
    int ret=1;
    int i;
    for(i=0;str[i]!='\0';i++){ //判断是否内容正确
        if(!((str[i]>='0')&&(str[i]<='9')||((str[i]>='a')&&(str[i]<='z'))||((str[i]>='A')&&(str[i]<='Z'))||str[i]=='_')){
            ret=0;
            break;
        }
    }
    if(str[0]>='0'&&str[0]<='9'){//数字不能为首位
        ret=0;
    }
    if(ret==1){
        printf("yes\n");
    }else{
        printf("no\n");
    }
}


int main(){
    int n;
    scanf("%d",&n);
    char str[n][50];
    int i;
    for(i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    for(i=0;i<n;i++){
        iflegal(str[i]);
    }
    return 0;
}