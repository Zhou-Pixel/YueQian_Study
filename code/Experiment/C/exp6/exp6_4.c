#include <stdio.h>
#include <string.h>

void linkstring(char *one, char *two)
{
    char linkstr[strlen(one) + strlen(two) + 1];
    for (int i = 0; i < strlen(one); i++)//把第一部分赋值
    {
        linkstr[i] = one[i];
    }
    for (int i = 0; i < strlen(two); i++)//第二部分赋值
    {
        linkstr[strlen(one) + i] = two[i];
    }
    linkstr[strlen(one) + strlen(two)] = '\0';
    printf("%s\n",linkstr);
    
    
}

void linkstringitself(char *one,char *two)
{
    
}

int main(int argc, char const *argv[])
{
    char one[] = "hello";
    char two[] = "world";
    linkstring(one, two);
    return 0;
}
