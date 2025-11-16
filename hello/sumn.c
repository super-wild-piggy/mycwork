#include <stdio.h>

int main()
{
    double a,b,c,sum,chu,i,n;
    printf("请给出你需要的项数n\n");
    scanf("%lf",&n); 
    a=1.0;
    b=2.0; 
    c=a+b;
    chu=b/a;
    sum=chu;
    for(i=2;i<=n;i++){
        a=b;
        b=c;
        c=a+b;
        chu=b/a;
        sum+=chu;
    }
    printf("%f",sum);
    return 0;
}