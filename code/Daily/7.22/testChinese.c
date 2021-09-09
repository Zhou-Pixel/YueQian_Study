#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char a[] = "中";
    printf("%d  %s\n",sizeof(a), a);
    printf("%d\n",strlen(a));
    return 0;
}
