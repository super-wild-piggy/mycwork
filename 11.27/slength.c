#include <stdio.h>
#include <string.h>

int main(){
    char s[1000];
    printf("请输入一串字符\n");
    scanf("%s",s);
    int length=strlen(s);
    int i=0,j,maxlen=1,len=1,k;
    for(j=1;j<length;j++){
        for(k=i;k<j;k++){
            if(s[k]==s[j]){
                i=k+1;
                break;
            }
        }
        len=j-i+1;
        if(maxlen<len){
            maxlen=len;
        }
    }
    printf("%d",maxlen);
    return 0;
}

/*第一次提交发现我只检查了边界的元素是否重复 没有检查字符串内部
窗口的大小可以用右边界-左边界+1 单纯的++浪费时间
左边界可以在发现重复时直接挪到重复值的右侧 不用一直++
使用双指针法时 在循环判断条件中的那个指针在循环内部不要改变值*/