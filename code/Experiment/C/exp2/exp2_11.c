#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    while (1)
    {
        c = getchar();
        printf("%c\n",c);

        if (c == EOF)
        {
            break;
        }
        
    }
    
    return 0;
}
