#include <stdio.h>
#include <string.h>

void strip(char *str)
{
    char substitute[strlen(str)];
    for (int i = 0, j= 0; i <= strlen(str); j++, i++)
    {
        while(str[i] == ' ')
        {
            i++;
        }
        substitute[j] = str[i];

    }
    strcpy(str, substitute);
    
}

void strip2(char *str)
{
    for (int i = 0, j = 0; j <= strlen(str); j++, i++)
    {
        if(str[i] == ' ')
        {
            while(str[j] == ' ')
                j++;
            str[i] = str[j];
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    char str[100];
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    strip2(str);
    printf("%s\n",str);
    return 0;
}
