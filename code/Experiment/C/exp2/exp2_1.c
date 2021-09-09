#include <stdio.h>

int main(int argc, char const *argv[])
{
     int count = 0;
        while (1)
        {
            count++;
            if (count < 0)
            {
                printf("最小值是：%d\n最大值是：%d\n",count,count-1);//一直加1，count小于0时就是最大值加1后变成最小值,count-1即为最大值
                break;
            }
            
        }
    return 0;
}
