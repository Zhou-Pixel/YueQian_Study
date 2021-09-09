#include <stdio.h>



int calculate(int num)
{
    int a[3] = {1, 1, 2};
    int sum = 1;
    for (int i = 0; i < num - 3; i++)
    {
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[0] + a[1];
    }
    return a[2];
}
int main(int argc, char const *argv[])
{
    printf("%d\n",calculate(10));
    return 0;
}
