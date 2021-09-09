#include <stdio.h>

void transform(double source[], double target[], int num, double (*p)(double))
{
    for (int i = 0; i < num; i++)
    {
        target[i] = p(source[i]);
    }
    
}


double transdouble(double i)//双倍
{
    return i*2;
}

int main(int argc, char const *argv[])
{
    double source[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double target[5];
    transform(source, target, 5, transdouble);
    for (int i = 0; i < 5; i++)
    {
        printf("%f\n",target[i]);
    }
    
    return 0;
}
