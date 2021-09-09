#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[5] = {1,2,3,4,5};
    printf("%d\n", sizeof(a));
    printf("%p\n",&a);
    printf("%p\n",a);
    printf("long int的大小:%d\n",sizeof(long int));
    return 0;
}
