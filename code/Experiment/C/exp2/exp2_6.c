#include <stdio.h>

int main(void)
{
    int x = 10;
    int a, b, c;
    a = x++; //a=10,x=11
    b = ++x; //b=12,x=12
    
    c = 10*x++; //c=120,x=13
    printf("x = % d，a = % d，b = % d，c = %d\n", x, a, b, c);
    return 0;
}