#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    /* code */
    int a[100];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        
        printf("%lld\n",rand());
    }
    
    
    return 0;
}
