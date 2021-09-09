#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    int b = &a[3] - &a[2];
    printf("%d\n",b);
    return 0;
}
