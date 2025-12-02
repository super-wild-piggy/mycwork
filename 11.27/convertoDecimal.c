#include <stdio.h>
#include <string.h>

int stringTurnNumber(char argv[]){
    char *protection=argv;
    int i,number[100],count=0;
    for(i=0;protection[i]!='\0';i++){
        number[i]=protection[i]-'0';
        count++;
    }
    int j,thistime=1;
    int goal=0;
    for(i=0;protection[i]!='\0';i++){
        for(j=count-1-i;j>0;j--){
            thistime*=10;
        }
        goal+=number[i]*thistime;
        thistime=1;
    }
    return goal;
}//好像还有更简单的逻辑
void turnNumber(int rule,char argv[]){
      int target=stringTurnNumber(argv);
        int i,number[100];
        int count=0;
        for(i=0;target!=0;i++){
            number[i]=target%10;
            target/=10;
            count++;
        }
        int goal=0,j,thistime=1;
        for(i=0;i<count;i++){
            for(j=1;j<=i;j++){
                thistime*=rule;
            }
            goal+=number[i]*thistime;
            thistime=1;
        }
        printf("The decimal value is:%d",goal);
}

int main(int argc,char *argv[]){    
    if(argc<2){
        printf("Usage:obh2dec.exe [-o][-b][-h] target\n");
        printf("-o the target is an octal number\n");
        printf("-b the target is a binary number\n");
        printf("-h the target is a hexadecimal number\n");
        printf("If all optional parameters are omitted,\n");
        printf("by default,the target is an octal number\n");
    }
    if(!strcmp(argv[1],"-o")){
        turnNumber(8,argv[2]);
    }else if(!strcmp(argv[1],"-h")){
        turnNumber(16,argv[2]);
    }else if(!strcmp(argv[1],"-b")){
        turnNumber(2,argv[2]);
    }else if(!strcmp(argv[2],"-o")){
        turnNumber(8,argv[1]);
    }else if(!strcmp(argv[2],"-h")){
        turnNumber(16,argv[1]);
    }else if(!strcmp(argv[2],"-b")){
        turnNumber(2,argv[1]);
    }else{
        printf("ERROR!!!\n\n\n");
        printf("Usage:obh2dec.exe [-o][-b][-h] target\n");
        printf("-o the target is an octal number\n");
        printf("-b the target is a binary number\n");
        printf("-h the target is a hexadecimal number\n");
        printf("If all optional parameters are omitted,\n");
        printf("by default,the target is an octal number\n");
    }
    return 0;
}