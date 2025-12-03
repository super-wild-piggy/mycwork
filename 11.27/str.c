#include <stdio.h>

int main(){
    char ch,str[1000];
    int i=0;
    while((ch=getchar())!='\n'){//输入回车结束输入
        str[i]=ch;
        i++;
    }
    str[i]='\0';//添加字符串结束标志
    int count=i;
    int j;
    char t;
    for(i=0;i<count;i++){//冒泡排序
        for(j=0;j<count-1-i;j++){
            if(str[j]>str[j+1]){
                t=str[j];
                str[j]=str[j+1];
                str[j+1]=t;
            }
        }
    }
    j=0;
    for(i=1;i<count;i++){//双指针法 i用来遍历数组 j用来记录位置
        if(str[i]!=str[j]){
            j++;
            str[j]=str[i];  //把不重复的字符拿上来
        }
    }
    str[j+1]='\0';
    printf("%s",str);
    return 0;


}