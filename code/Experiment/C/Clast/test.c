#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen(argv[1],"r");
    char getstring[20];
    while (fgets(getstring,20,fp) != NULL)
    {
        // getstring[strlen(getstring) - 2] = '\0';

        printf("%d %s",strlen(getstring), getstring);
        printf("%d\n",getstring[strlen(getstring) - 1]);
    }
    
    fclose(fp);
    return 0;
}
