#include <stdio.h>

float myPower(float x, int N)//循环
{
    float a = x; //把x的值赋给a保证for循环相乘的数值是不变的
    if (N < 0)
    {
        for (int i = 0; i < -N - 1; i++) //N需要-1
        {
            x = x * a;
        }
        x = 1.0 / x;
    }
    else if (N == 0 && x != 0)
    {
        x = 1;
    }
    else
    {

        for (int i = 0; i < N - 1; i++)
        {
            x = x * a;
        }
    }
    return x;
}
float myPower2(float x, int N)//递归
{
    if (x == 0)
    {
        return -1;
    }
    else if (N == 0)
    {
        return 1;
    }else if (N >0)
    {
        return myPower2(x, N - 1) * x;
    }else
    {
        return myPower2(x, N + 1) * (1/x);
    }
    
    

    
}

int main(int argc, char const *argv[])
{

    printf("%f\n", myPower(2, -3));
    printf("%f\n", myPower2(3.14, 10));
    return 0;
}

