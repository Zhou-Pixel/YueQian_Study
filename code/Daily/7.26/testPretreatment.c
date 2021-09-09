#include <stdio.h>

#define A 0
#define B 2

int main(int argc, char const *argv[])
{

    #if B
    printf("%d\n",__LINE__);

    #endif
    return 0;
}
