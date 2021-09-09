#include <stdio.h>


int ismax(int a, int b, int c)
{
    int max = a;
    max = max > b ? max : b;
    max = max > c ? max : c;
    return max;
}
int main(int argc, char const *argv[])
{
    printf("最大：%d\n",ismax(23,45,12));
    return 0;
}
