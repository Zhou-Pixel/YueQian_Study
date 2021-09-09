#include <stdio.h>
#define COLORPRINTF(color, msg) do{\
    switch (color)\
    {\
    case red:\
        printf("\033[1;31m %s\n\033[m",msg);\
        break;\
    \
    case blue:\
        printf("\033[0;32;34m %s\n\033[m",msg);\
        break;\
\
    case yellow:\
        printf("\033[1;33m %s\n\033[m",msg);\
        break;\
\
    case green:\
        printf("\033[0;32;32m %s\n\033[m",msg);\
        break;\
    }\
}while(0)

enum {red,blue,yellow,green};


int main(int argc, char const *argv[])
{

    COLORPRINTF(red,"abcd");
    COLORPRINTF(blue,"abcd");
    COLORPRINTF(yellow,"abcd");
    COLORPRINTF(green,"abcd");

    return 0;
}
