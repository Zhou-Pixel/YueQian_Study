#include <stdio.h>

int func()
{
    static int count = 0;
    // count++;
    // printf("被调用的次数：%d\n",count);
    return ++count;
}

int main(int argc, char const *argv[])
{
    int i;
    while (i < 10)
    {
        
        printf("%d\n",func());
        i++;
    }
    
    return 0;
}
