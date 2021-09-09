#include <stdio.h>
#include <string.h>

void handle(char *ch,char *last)
{
    // for (int i = 0, j = 0; i <= strlen(ch); i++)
    // {
    //     while(ch[i] == -1)//用if处理不了连续两个-1，需要用while
    //     {
    //         i++;
    //     }
    //     last[j] = ch[i];
    //     printf("%c\n",last[j]);

        
    //     j++;
        
        
    // }


    int i = 0, j = 0;
    while (1)
    {
        while(ch[i] == -1)//用if处理不了连续两个-1，需要用while
        {
            i++;
        }
        last[j] = ch[i];
        if (last[j] == '\0')
        {
            break;
        }
        
        i++;
        j++;
    }
    
    
}


int main(int argc, char const *argv[])
{
    char ch[100];
    scanf("%s", ch);
    for (int i = 0; i < strlen(ch); i++)
    {
        for (int j = i + 1; j < strlen(ch); j++)
        {
            if (ch[i] == ch[j])
            {
                
                ch[j] = -1;
            }
        }
    }
    char last[strlen(ch)];
    handle(ch,last);
    printf("%s\n", last);

    return 0;
}
