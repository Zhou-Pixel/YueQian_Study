#include <stdio.h>


union attr
{
    int x;
    char y;
    double z;  
}at;
int main(int argc, char const *argv[])
{
    at.x = 100;
    at.y = '1';
    at.y = 1.00;
    printf("%p\n",at.x);
    printf("%p\n",at.y);
    printf("%p\n",at.z);
    return 0;
}
