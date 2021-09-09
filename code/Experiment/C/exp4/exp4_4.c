#include <stdio.h>
#include <stdbool.h>



int main(int argc, char const *argv[])
{
    int a[7] = {-2, 5, -1, 6, -4, -8, 6};
    int sum = 0, max = a[0];
    bool begin = true;//要设置一个开始标记，不然while循环每次都会运行
    for (int i = 0; i < 7; i++)
    {
        while (a[i] < 0 && begin == true)
        {
            i++;
            max = max >= a[i] ? max : a[i];
            // printf("while:%d\n", max);
        }
        begin = false;

        sum += a[i];
        max = sum > max ? sum : max;
        if (sum < 0)
        {
            sum = 0;
        }

        // printf("for:%d\n", max);
    }
    printf("max：%d\n", max);
    return 0;
}
