#include <stdio.h>
#include <string.h>

int main(){
    char before[1000];
    char name[100][10];
    scanf("%s",before);
    int j=-1,k=0;//名字的位置 和字符的位置
    for(int i=0;before[i]!='\0';i++){
        if(before[i]>='A'&&before[i]<='Z'){
            if(j!=-1){
                name[j][k+1]='\0';
            }
            k=0;
            j++;
            name[j][k]=before[i];
        }else{
            k++;
            name[j][k]=before[i];
        }
    }
    name[j][k+1]='\0';
    int count=j+1;//名字的个数
    int p[count];//用来记录上一次接上的名字的位置
    int countorder[count];
    countorder[0]=1;
    p[0]=-1;
    for(int i=1;i<count;i++){
        int maxCount=0;
        p[i]=-1;
        for(int m=0;m<i;m++){
            if(maxCount<countorder[m]&&strcmp(name[m],name[i])<0){
                maxCount=countorder[m];
                p[i]=m;//记录能接的最长的上一位的位置
            }
        }
        countorder[i]=maxCount+1;//加上自己
    }
    int end=0;//记录最长递增字符串的最后一位的位置
    for(int i=1;i<count;i++){
        if(countorder[end]<countorder[i]){
            end=i;
        }
    }
    char after[countorder[end]][10];
    int position=end;
    for(int i=0;i<countorder[end];i++){
        strcpy(after[i],name[position]);
        position=p[position];
    }
    for(int i=countorder[end]-1;i>=0;i--){
        printf("%s",after[i]);
    }
    return 0;
}