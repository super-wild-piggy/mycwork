#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c,derta;
    printf("Please input a b c");
    scanf("%lf %lf %lf",&a,&b,&c);
    derta=b*b-4*a*c;
    if(derta>0){
         double root= sqrt(derta);
         printf("x1=%f,x2=%f",(root-b)/(2*a),(-b-root)/(2*a));
     }
     else if(derta==0){
        printf("x=%f",-b/(2*a));
     }
     else{
        printf("方程在实数范围内无解");
     }
   
    return 0;
}