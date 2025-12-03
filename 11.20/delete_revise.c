#include <stdio.h>
#include <string.h>

int main(){
    char str[1000];
    printf("请输入\n");
    gets(str);
    int len=strlen(str);
    int i,j;
    j=0;
    for(i=1;i<len;i++){
        if(str[j]!=str[i]){
            j++;
            str[j]=str[i];  //j用来记录数据走到哪里了  把不同的拿上来
        }
    }
    str[j+1]='\0'; //把最后裁掉
    puts(str);
    return 0;
}

/*修改后的版本使用双指针法
此方法为快慢指针法
j是慢指针 用来记录位置
i是快指针 用来遍历数组*/