#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;

    char s[10];
    while(1)
    {
        printf("请输入int型数据：\n");
        int retValue = scanf("%d", &n);
        /* char c =getchar();
        printf("%s\n",c); */

        if(retValue == 1 && getchar() == '\n')
            break;

        else
        {
            printf("温馨提示：请不要给我别的数据，再给你一次机会\n");
            // 清空残留的非法数据
            // fgets(s, 10, stdin);
            // 每次读取键盘输入的一个字符，直到将最后的回车符也读掉为止
            while(getchar() != '\n');
        }
    }

    printf("很好！%d\n", n);

    return 0;
}
