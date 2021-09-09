#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */

    int a = 0;
    if(++a)
    printf("%d\n",__LINE__);
    return 0;
}
