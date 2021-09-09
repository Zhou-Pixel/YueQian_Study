#include <stdio.h>

int main(int argc, char const *argv[])
{
    long int a[5] = {1,2,3,4,5};
    long int *p = a;
    printf("%p,%p,%p,%p,%p\n",a,(p+1),&a[2],&a[3],&a[4]);//每个地址都差8，因为long int占8个字节，p+1代表p加了一个long int
    return 0;
}
