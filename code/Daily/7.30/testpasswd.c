#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char passwd[] = "123456789";
    char input[11];
    scanf("%s",input);
    if(strcmp(input,passwd))
    {
        printf("错误\n");
    }
    return 0;
}
