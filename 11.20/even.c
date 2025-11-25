#include <stdio.h>

void evenmax(int n,int ret[n][n]){
    int square[n][n];
    int i,j,k,l; 
    int number=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            square[i][j]=number++;
        }
    }
    k=0;
    int size=(n*n)/16;
    int takeout[8*size];
        for(i=0;i<n;i++){
            if((i+1)%4==1||(i+1)%4==0){
                for(j=0;j<n;j++){
                    if((j+1)%4==1||(j+1)%4==0){
                            takeout[k++]=square[i][j];
                            square[i][j]=0;
                    }
                }
            }else{
                for(j=0;j<n;j++){
                    if((j+1)%4==2||(j+1)%4==3){
                        takeout[k++]=square[i][j];
                        square[i][j]=0;
                    }
                }
            }
        }
    
    for(i=0;i<size*8-1;i++){
        for(j=0;j<size*8-1-i;j++){
            if(takeout[j]<takeout[j+1]){
                l=takeout[j];
                takeout[j]=takeout[j+1];
                takeout[j+1]=l;
            }
        }
    }
    k=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(square[i][j]==0){
                    square[i][j]=takeout[k++];
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                ret[i][j]=square[i][j];
            }
        }
    }

void odd(int n,int start_num,int ret[n][n]){
    int square[n][n];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            square[i][j]=0;
        }
    }
    square[0][(n+1)/2-1]=start_num;
    int r0=1,c0=(n+1)/2;
    int r1,c1;
    for(i=start_num+1;i<=n*n+start_num-1;i++){
        if(r0==1&&c0!=n){
            r1=n;
            c1=c0+1;
        }else if(r0!=1&&c0==n){
            r1=r0-1;
            c1=1;
        }else if(r0==1&&c0==n){
            r1=r0+1;
            c1=c0;
        }else{
            r1=r0-1;
            c1=c0+1;
        }
        if(square[r1-1][c1-1]==0){
            square[r1-1][c1-1]=i;
        }else{
            r1=r0+1;
            c1=c0;
            square[r1-1][c1-1]=i;
        }
        r0=r1;
        c0=c1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ret[i][j]=square[i][j];
        }
    }
}

void evenmin(int n,int ret[n][n]){
    int square[n][n];
    int i,j;
    int A[n/2][n/2];
    int B[n/2][n/2];
    int C[n/2][n/2];
    int D[n/2][n/2];
    odd(n/2,1,A);
    odd(n/2,1+n*n/4,D);
    odd(n/2,1+2*n*n/4,B);
    odd(n/2,1+3*n*n/4,C);
    for(i=0;i<n/2;i++){
        for(j=0;j<n/2;j++){
            square[i][j]=A[i][j];
        }
    }
    for(i=0;i<n/2;i++){
        for(j=n/2;j<n;j++){
            square[i][j]=B[i][j-n/2];
        }
    }
    for(i=n/2;i<n;i++){
        for(j=0;j<n/2;j++){
            square[i][j]=C[i-n/2][j];
        }
    }
    for(i=n/2;i<n;i++){
        for(j=n/2;j<n;j++){
            square[i][j]=D[i-n/2][j-n/2];
        }
    }
    int k=n/4;
    int t;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j<k&&i<n/2&&i!=k){
                t=square[i][j];
                square[i][j]=square[i+n/2][j];
                square[i+n/2][j]=t;
            }else if(i==k&&j>=k&&j<2*k){
                t=square[i][j];
                square[i][j]=square[i+n/2][j];
                square[i+n/2][j]=t;
            }else if(j==3*k&&i<n/2){
                t=square[i][j];
                square[i][j]=square[i+n/2][j];
                square[i+n/2][j]=t;
            }
        }
    }
    for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                ret[i][j]=square[i][j];
            }
        }
}
int main(){
    int n;
    printf("请输入一个偶数n\n");
    scanf("%d",&n);
    int ret[n][n];
    if(n%4==0){
        evenmax(n,ret);
    }else{
        evenmin(n,ret);
    }
    int count=0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",ret[i][j]);
            count++;
            if(count%n==0){
                printf("\n");
            }else{
                printf("  ");
            }
        }
    }
}

/*二维数组遍历要赋递增的值需要用++
for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            square[i][j]=number++;
        }
    }
把数组的值赋进另一个数组也用++ （2维变1维）
for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(square[i][j]==0){
                    square[i][j]=takeout[k++];
                }
            }
        }
函数可以通过参数返回数组*/