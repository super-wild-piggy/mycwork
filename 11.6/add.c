#include <stdio.h>

int main(){
    char str1[1000];
    char str2[1000];
    scanf("%s",str1);
    scanf("%s",str2);
    long long int num1,num2;
    sscanf(str1,"%lld",&num1);
    sscanf(str2,"%lld",&num2);
    printf("%lld",num1+num2);
}
