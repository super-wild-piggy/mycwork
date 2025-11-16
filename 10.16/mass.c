#include <stdio.h>

int main()
{
    char a='A';
    int b=243;
    short int c=335;
    long int d=34546;
    long long int f=243254654;
    float g=1.0;
    double h=2.0;
    long double i=3.0;
    printf("a=%d\n",sizeof(a));
    printf("b=%d\n",sizeof(b));
    printf("c=%d\n",sizeof(c));
    printf("d=%d\n",sizeof(d));
    printf("f=%d\n",sizeof(f));
    printf("g=%d\n",sizeof(g));
    printf("h=%d\n",sizeof(h));
    printf("i=%d\n",sizeof(i));
    return 0;
}