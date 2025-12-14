#include <stdio.h>
#include <string.h>

void search(char *array,char *array_search,char *array_replace){
    int len=strlen(array);
    int slen=strlen(array_search);//要搜索的字符串的长度
    int rlen=strlen(array_replace);
    int ret=1;//判断是否存在可替换项
    int count=0;
    for(int i=0;i<=len;i++){
        for(int j=i;j<i+slen;j++){
            if(array[j]!=array_search[j-i]){
                ret=0;
                break;
            }
        }
        if(ret){
            char t[100];
            int m=0;//中间字符串计数器
            int k;
            for(k=i+slen;k<len;k++){
                t[m]=array[k];
                m++;
            }
            t[m]='\0';
            m=0;
            for(k=i;k<i+rlen;k++){
                array[k]=array_replace[m];
                m++;
            }
            array[k]='\0';
            strcat(array,t);
            len=strlen(array);
        }
        ret=1;
    }
}

int main(){
    char array[100],array_search[20],array_replace[20];
    gets(array);
    gets(array_search);
    gets(array_replace);
    search(array,array_search,array_replace);
    puts(array);
}

/*字符串处理时尽量使用字符串函数
当循环判断条件被改变时要及时更改
例如本题的长度 
我的目的是改变长度
但是循环条件却没有改
导致程序错误*/