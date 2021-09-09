#include <stdio.h>

int main(int argc, char const *argv[])
{
    //(1)
    int a[3][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int *p = &a[2][3];
    //(2)&a[2][0]   a[2]
    //(3) a[0]  &a[0][0] a




    printf("%p\n",a[0]);
    printf("%p\n",&a[0][0]);
    printf("%p\n",*a);

    return 0;
}
