#include <stdio.h>
#include <ctype.h>

int change(char *str, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (islower((int)str[i]))
        {
            str[i] -= 32;
        }
    }
    
    return 0;
}
int main(int argc, char const *argv[])
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    change(str, sizeof(str));
    printf("%s\n",str);
    return 0;
}
