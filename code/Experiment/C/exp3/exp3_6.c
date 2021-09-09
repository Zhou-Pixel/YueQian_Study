#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    scanf("%d", &input);
    char output[100];
    int i;
    for (i = 0;; i++)
    {
        int a = input % 16;
        printf("余数%d\n", a);
        switch (a)
        {
        case 10:
            output[i] = 'A';
            break;
        case 11:
            output[i] = 'B';
            break;
        case 12:
            output[i] = 'C';
            break;
        case 13:
            output[i] = 'D';
            break;
        case 14:
            output[i] = 'E';
            break;
        case 15:
            output[i] = 'F';
            break;
        default:
            output[i] = a + 48;
            break;
        }
        if (input == 0)
        {
            break;
        }
        
        input = input / 16;
        // printf("input:%d\n", input);
        // printf("循环内i:%d\n", i);
    }



    printf("循环外i:%d\n", i);
    printf("十六进制：%s", "0x");
    for (int a = i-1; a >= 0; a--)
    {
        printf("%c", output[a]);
    }
    printf("\n");

    return 0;
}
