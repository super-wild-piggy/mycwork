#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    printf("请输入一串字符串\n");
    scanf("%s",str);
    int i,j;
    for(i=0;i<strlen(str);i++){
        if(str[i]==str[i+1]){
            for(j=i;j<strlen(str)-1;j++){
                str[j]=str[j+1];
                if(j+1==strlen(str)-1){
                    str[j+1]='\0';
                }
            }
            i--;
        }
    }
    printf("%s",str);
    return 0;
}


