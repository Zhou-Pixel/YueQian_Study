#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0x12345678;
    int *p = &a;
    printf("%#x\n",*((char *)p));//输出想0x78，小端序
    return 0;
}
