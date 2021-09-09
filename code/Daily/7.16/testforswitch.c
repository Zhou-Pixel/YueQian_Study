#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i; i < 10; i++)
    {
        switch (i)
        {
        case 8:
            printf("switch内\n");
            break;
        
        default:
            break;
        }
        if (i == 8)
        {
            printf("if内\n");
        }
        
    }
    return 0;
}
