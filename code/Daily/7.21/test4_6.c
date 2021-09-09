#include <stdio.h>
#include <string.h>

void strip(char *str)
{
    if (str == NULL)
        return;

    int i, j;
    char *p = str;

    // 将所有重复的字符标记为-1
    for (i = 1; str[i] != '\0'; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (p[j] == str[i])
            {
                str[i] = -1;
                break;
            }
        }
    }

    // 找到第一个-1的位置 redun
    // 找到紧随 redun 之后的正常字符的位置 common
    int redun = 0, common = 0;
    for (i = 1; str[i] != '\0'; i++)
    {
        if (str[i] != -1)
            continue;

        redun = i;
        while (str[i] == -1)
            i++;

        common = i;
        break;
    }

    // 若没有重复的字符，则返回
    if (redun == 0)
        return;

    // 将所有正常字符往前移
    while (str[common] != '\0')
    {
        if (str[common] == -1)
        {
            common++;
            continue;
        }
        str[redun++] = str[common];
        str[common++] = -1;
    }
    str[redun] = '\0';
}

int main(void)
{
    system("ls");

    // 输入待处理字符串
    char buf[64];
    fgets(buf, 64, stdin);

    strip(buf);
    printf("%s", buf);

    return 0;
}