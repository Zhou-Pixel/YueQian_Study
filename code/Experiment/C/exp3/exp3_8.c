#include <stdio.h>
#include <limits.h>
#include <ctype.h>

void upperCase(char str[])
{
    int step = 'a' - 'A';
    printf("测试大小%d  %d %d\n",sizeof(str),sizeof(str[0]),sizeof(str)/sizeof(str[0]));//结果是8 1 8 传进来的str是地址
    for(int i = 0; i<sizeof(str)/sizeof(str[0]); i++)
    {
        if(islower(str[i]))
        {
            str[i] -= 32;
            printf("成功\n");
        }
    }
}
int main(void)
{
    char str[] = "abcdefghijklnmopqrstuvwxyz";
    printf("原数组：%s\n", str);
    upperCase(str);
    printf("转换后：%s\n", str);
}