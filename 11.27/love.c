#include <stdio.h>
#include <string.h>

int Count_substring(char *text,char *pattern){
    int length=0;
    int i,j;
    for(i=0;pattern[i]!='\0';i++){
        length++;
    }
    int count=0;
    int ret=1;
    int k=0;
    for(i=0;text[i+length-1]!='\0';i++){
        for(j=i;j<i+length;j++){
            if(text[j]!=pattern[k]&&text[j]!=pattern[k]+'A'-'a'&&text[j]!=pattern[k]+'a'-'A'){
                ret=0;
                k=0;
                break;
            }else{
                k++;
            }
        }
        if(ret==1){
            count++;
        }
        ret=1;
        k=0;
    }
    return count;
}

int main(){
    char text[1000],pattern[100];
    int i=0;
    char ch;
    while((ch=getchar())!='\n'){
        text[i]=ch;
        i++;
    }
    text[i]='\0';
    i=0;
    while((ch=getchar())!='\n'){
        pattern[i]=ch;
        i++;
    }
    pattern[i]='\0';
    printf("%d",Count_substring(text,pattern));
    return 0;
}

/*第一次报错：getchar函数没有参数 不应该在括号里写参数
getchar写完后要再字符串最后添加'\0'
第二次报错：pattern判断完一次后没有回去
第三次报错：break的位置错误*/