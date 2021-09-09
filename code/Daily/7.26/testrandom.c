#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    /* code */
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        /* code */
        printf("%d\n",rand()%20);
    }
    
    return 0;
}
