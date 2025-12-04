#include <stdio.h>

int main(){
    char key[51],ch;
    int i,j;
    int count=0;
    i=0;
    while((ch=getchar())!='\n'){
        key[i]=ch;
        i++;
    }
    key[i]='\0';
    for(i=0;key[i]!='\0';i++){
        count++;
    }
    for(i=0;i<count;i++){
        for(j=i+1;j<count;j++){
            if(key[i]==key[j]){
                for(int k=j;k<count;k++){
                    key[k]=key[k+1];
                }
                count--;
                j--;
            }
        }
    }
    char reversekey[count+27];
    j=count-1;
    for(i=0;i<count;i++){
        reversekey[i]=key[j];
        j--;
    }
    char standard='z';//准备添加逆序字母表
    for(i=count;i<count+26;i++){
        reversekey[i]=standard;
        standard--;
    }
    reversekey[i]='\0';
    for(i=0;i<count+26;i++){
        for(j=i+1;j<count+26-1;j++){
            if(reversekey[i]==reversekey[j]){
                for(int k=j;k<count+26;k++){
                    reversekey[k]=reversekey[k+1];
                }
                count--;
                j--;
            }
        }
    }
    reversekey[26]='\0';
    char str[1000];
    i=0;
    while((ch=getchar())!='\n'){
        str[i]=ch;
        i++;
    }
    str[i]='\0';
    int countstr=i;
    char turned_str[countstr+1];
    for(i=0;i<countstr;i++){
        if(str[i]<='Z'&&str[i]>='A'){
            turned_str[i]=reversekey[str[i]-'A']-('a'-'A');
        }else if(str[i]<='z'&&str[i]>='a'){
            turned_str[i]=reversekey[str[i]-'a'];
        }else{
            turned_str[i]=str[i];
        }
    }
    turned_str[i]='\0';
    printf("%s",turned_str);
    return 0;
}

/*我的双指针法无法解决隔项去重
疑问：为什么之前的key使用scanf读入 后面用getchar就不行了*/

//根据ai提示更正 当删除一个重复字符后 j应该保持不变 因为后面的字符前移了
//ai回答我的问题：因为用scanf读取密钥时 会在缓冲区里留下一个换行符
//而getchar又会读取到这个换行符 导致提前结束

//第二次发现问题 在for循环后我想要给最后一位赋'\0'但是数组越界了