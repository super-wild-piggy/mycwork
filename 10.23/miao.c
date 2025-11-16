#include <stdio.h>

int main()
{
    int x;
    x=getchar();
    if(x>=97){
        x-=32;
        printf("%c",x);
    }else{
        x+=32;
        printf("%c",x);
    }
    return 0;
}