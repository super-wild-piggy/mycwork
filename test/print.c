#include <stdio.h>
#include <string.h>


int main(){
    char str[1000][1000];
    int i,j;
    int count=0;//记录字符串行数
    while(fgets(str[count],1000,stdin)!=NULL&&count<1000){
        str[count][strcspn(str[count],"\n")]='\0';//去除换行符
        count++;
    }
    int compare_position=0;
    char t[1000];
    for(i=0;i<count;i++){
        for(j=0;j<count-1-i;j++){
            compare_position=0;
            while(str[j][compare_position]!='\0'&&str[j+1][compare_position]!='\0'&&str[j][compare_position]==str[j+1][compare_position]){
                compare_position++;
            }//或者直接使用strcmp函数
            if(str[j][compare_position]>str[j+1][compare_position]){
                strcpy(t,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],t);
            }
        }
    }
    for(i=0;i<count;i++){
        printf("%s",str[i]);
        if(i<count-1){
            printf("\n");
        }
    }
    return 0;
}

/*要点：
字符串之间不能相互赋值 要使用strcpy函数
fgets函数要去除换行符 要使用strcspn函数*/