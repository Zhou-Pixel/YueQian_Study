#include <stdio.h>

#define MIN(x,y)   ({typeof(x) _x = x;\
                    typeof(y) _y = y;\
                    (void)(&_x == &_y);\
                    _x < _y ? _x : _y;})

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 5;
    printf("%d\n",MIN(10,5));
    return 0;
}
