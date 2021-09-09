#include <stdio.h>
int main(int argc, char const *argv[])
{
    int N;
    while (1)
    {
        printf("多少升\n");
        if (scanf("%d", &N) == 1 && getchar() == '\n') //scanf的输入都是一回车键\n结尾，验证读取的数据下一位是不是\n即可验证输入的数据是否正确和读取完整
        {
            printf("成功\n");
            break;
        }

        else
        {
            char c;
            while ((c = getchar()) != '\n') //清空缓存
            {
                printf("清空缓存中: %c\n", c);
            }
        }
        printf("失败，再试一遍\n");
    }
    float i = N / 3.02e-23L;
    printf("最终结果:%f\n",i);
    return 0;
}
