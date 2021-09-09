#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int input;
    scanf("%d",&input);
    for(int a = 2;a <= input;a++)
    {
        int count = 0;
        for(int b = 2;b <= a/2;b++)
        {
            if (a%b == 0)
            {
                count++;//计算被整除的次数
             
            }     
        }

        if (count == 0)
        {
            printf("%d是素数\n",a);//一次整除都没有就是素数
        }
    }
    return 0;
}
