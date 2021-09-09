#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    while(i<10)
    {
        static int j = 0;
        j++;
        i++;
        printf("%d\n",j);
        
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",i);
    }
    
    return 0;
}
