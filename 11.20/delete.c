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


/*报错原因
1、不会进行字符串常量比较 错误使用strcmp函数
2、循环结构出现问题 无法停止循环 最后在调试过程中发现是因为结尾添加'\0'的位置错误 
从而导致strlen函数计算错误
3、循环代替数据的过程中（往前移动数据）发现最后一个连续无法消去 
是因为在移动数据的过程中没有把最后一个元素赋值为'\0'*/