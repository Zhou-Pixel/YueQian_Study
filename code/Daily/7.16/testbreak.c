#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    for(i=0;;i++)
    {
        if (!(i < 10))
        {
            break;
        }
        
    }
    printf("%d\n",i);
    return 0;
}
