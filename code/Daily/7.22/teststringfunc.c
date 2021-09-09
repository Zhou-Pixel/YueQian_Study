#include <stdio.h>
#include <string.h>



int main(int argc, char const *argv[])
{
    char one[] = "abcd.txt.exe";
    char two[] = ".txt";
    char *p = strstr(one,two);
    if (p == NULL)
    {
        printf("没有\n");
    }
    else if( strcmp(one,two) == 0)
    {
        printf("有\n");
    }
    printf("%s\n",p);
    return 0;
}
