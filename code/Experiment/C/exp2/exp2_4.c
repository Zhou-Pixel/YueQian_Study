#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 1;
    int n;
    while (1)
    {
        if (scanf("%d", &n) == 1 && getchar() == '\n')
        {

            printf("成功\n");
            break;
        }
        else
        {
            while (getchar() != '\n')
            {
            }
        }
    }
    int a;
    for (a = 0; sum <= n; sum++)
    {
        a += sum;
    }
    printf("a = %d\n", a);
    return 0;
}
