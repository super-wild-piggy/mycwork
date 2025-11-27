#include <stdio.h>
#include <string.h>

int main(){
    char s[1000];
    printf("请输入一串字符\n");
    scanf("%s",s);
    int length=strlen(s);
    int i=0,j,maxlen=1,len=1,k;
    for(j=1;j<length;j++){
        if(s[j]!=s[i]){
            len++;
        }else{
            i++;
            len--;
        }
        if(maxlen<len){
            maxlen=len;
        }
    }
    printf("%d",maxlen);
    return 0;
}