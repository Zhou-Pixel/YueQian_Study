#include <stdio.h>
#include <string.h>

void removespace(char *str)//新建一个字符串，进行赋值
{
    char newstr[strlen(str) + 1];
    for (int i = 0, j = 0; i <= strlen(str); j++, i++)
    {
        while(str[i] == ' ')//用while来处理连续的空格
        {
            i++;
        }
        newstr[j] = str[i];
        
    }
    printf("%s\n",newstr);

}
void removespaceitself(char *str)//在原来的字符串上面操作
{
    for (int i = 0, j = 0; j <= strlen(str);j++, i++)
    {
        if (str[i] == ' ')
        {
            while(str[j] == ' ')
            {
                j++;
            }
            str[i] = str[j];
            
        }
    }
    
}

int main(int argc, char const *argv[])
{
    char a[100];
    fgets(a,100,stdin);
    printf("前%s\n",a);
    // removespace(a);
    removespaceitself(a);
    printf("后%s\n",a);




    
    
    return 0;
}
