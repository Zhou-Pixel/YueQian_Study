#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("hello world");
    close(STDOUT_FILENO);
    return 0;
}
//什么都不输出
