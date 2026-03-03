#include <stdio.h>

int main(){
    int n;
    char c;
    scanf("%d %c",&n,&c);
    int ifexactly=0;
    int number=1;
    int total=n;
    n=n-1;
    int used=1;
    for(int i=3;used<=total;i=i+2){
        if(used==total){
            ifexactly=1;
            break;
        }else if(total-used<2*i){
            n=total-used;
            break;
        }
        else{
            number=number+2;
            used=used+number*2;
            
        }
    }
    int row=number;
    for(int i=0;i<number/2;i++){
        if(row==number){
            for(int j=0;j<row;j++){
                printf("%c",c);
            }
            printf("\n");
            row=row-2;
        }else{
            for(int j=0;j<(number-row)/2;j++){
                printf(" ");
            }
            for(int j=0;j<row;j++){
                printf("%c",c);
            }
            
            printf("\n");
            row=row-2;
        }
    }
    for(int j=0;j<(number-row)/2;j++){
                printf(" ");
            }
            for(int j=0;j<row;j++){
                printf("%c",c);
            }
            printf("\n");
            row=row+2;
    for(int i=0;i<number/2;i++){
        if(row==number){
            for(int j=0;j<row;j++){
                printf("%c",c);
            }
            printf("\n");
        }else{
            for(int j=0;j<(number-row)/2;j++){
                printf(" ");
            }
            for(int j=0;j<row;j++){
                printf("%c",c);
            }
            printf("\n");
            row=row+2;
        }
    }
    printf("%d",total-used);
    return 0;
}

/*不可以用一个变量表示好几种意思*/