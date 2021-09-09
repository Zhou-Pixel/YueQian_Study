#include <stdio.h>

int acceptarray(int a[],int b[],int c[],int length)
{
    for (int i = 0; i < length; i++)
    {
        c[i] = a[i] + b[i];
    }
    
}
int main(int argc, char const *argv[])
{
    int a[5]={1,2,3,4,5};
    int b[5]={1,2,3,4,5};
    int c[5];
    acceptarray(a,b,c,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",*(c+i));
    }
    
    return 0;
}
