#include <stdio.h>
#include <strings.h>

void strip(char s[])
{
    // 找到i和j
    int i, j;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i] == ' ')
            break;
    }

    for(j=i; s[j]!='\0'; j++)
    {
        if(s[j] != ' ')
            break;
    }

    // 将j指向的正常字符，不断地往前移动
    while(s[j] != '\0')
    {
        s[i++] = s[j++];

        while(s[j] == ' ' && s[j] != '\0')
            j++;
    }

    s[i] = s[j];
}

int main(int argc, char const *argv[])
{
    char s[20];
    bzero(s, 20);

    // 从键盘接收一串字符
    fgets(s, 20, stdin);

    strip(s);
    printf("%s", s);

    return 0;
}
