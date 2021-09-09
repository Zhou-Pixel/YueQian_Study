#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = i;//赋值
        }
        
    }
    
    int (*b[4])[4];
    for (int i = 0; i < 4; i++)
    {
        b[i] = &a[i];
    }
    
    



    int sum = 0;
    for (int i = 0; i < 4; i++)//计算和
    {
        for (int j = 0; j < 4; j++)
        {
            sum += (*b[i])[j];//赋值
        }
        
    }

    printf("最终结果%d\n",sum);
    return 0;
}
