#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch = 'A';
    char input = getchar();
    int lines = input - ch + 1;
    for (int i = 1; i <= lines; i++)
    {
        for (int j = 0; j < lines-i; j++)
        {
            printf(" ");//负责打印所有空格

        }
        for (int a = 0;  a < i; a++)
        {
            printf("%c",ch+a);//打印升序的字母
        }
         for (int b = i-1; b > 0; b--)
         {
             printf("%c",ch+b-1);//打印降序的字母
         }
         
        
        printf("\n");
    }
    
    return 0;
}
