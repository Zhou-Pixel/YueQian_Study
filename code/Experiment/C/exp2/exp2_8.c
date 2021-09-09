#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int one = 0x12344520;
    unsigned int two = 0xff004b1c;
    unsigned int three = 0x00553c1e;
    // unsigned int temmask = 255;
    // unsigned int bhummask = 255<<8;
    // unsigned int doormask = 15<<16;
    // unsigned int lightmask = 15<<20;
    // int one_tem = temmask & one;
    // int two_tem = temmask & two;
    unsigned int tem = (one<<24)>>24;
    printf("温度：%d\n",tem);
    unsigned int humidity =(one<<16)>>24;
    printf("湿度：%d\n",humidity);


    unsigned int door = (one<<12)>>28;//获取四个门的数据
    unsigned int light = (one<<8)>>28;//获取灯的数据

    for (int i = 1; i <= 4; i++)
    {
        if ((door<<(32-i))>>31)//单独提取每一个位的数据
        {
            printf("第%d个门是开的\n",i);
        }
        else
        {
            printf("第%d个门是关的的\n",i);
        }
        
    }
    
    for (int i = 1; i <= 4; i++)
    {
        if ((light<<(32-i))>>31)//单独提取每一个位的数据
        {
            printf("第%d个灯是开的\n",i);
        }
        else
        {
            printf("第%d个灯是关的的\n",i);
        }
        
    }
    



    return 0;
}
