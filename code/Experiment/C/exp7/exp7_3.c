#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *p = malloc(20);
    strcpy(p, "abcdefg");

    free(p);
    printf("%s\n", p);//释放内存，但是系统不一定立刻会使用你free掉的内存，所以继续访问不一定会出现问题

    return 0;
}