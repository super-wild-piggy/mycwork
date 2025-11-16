#include <stdio.h>

/*int main() {
    char str[] = "China";
    int i;
    
    printf("原始字符串: %s\n", str);
    printf("加密后: ");
    
    for (i = 0; str[i] != '\0'; i++) {
        // 对每个字符进行加密
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // 大写字母处理
            str[i] = 'A' + (str[i] - 'A' + 4) % 26;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            // 小写字母处理
            str[i] = 'a' + (str[i] - 'a' + 4) % 26;
        }
        // 如果不是字母，保持不变
    }
    
    printf("%s\n", str);
    return 0;
}*/

int main(){
    char str[]="China";
    int i;
    for(i=0;i<sizeof(str)/sizeof(str[0]);i++){
        str[i]+=4;
        printf("%c\n",str[i]);
    }
    printf("%s",str);
    return 0;
}