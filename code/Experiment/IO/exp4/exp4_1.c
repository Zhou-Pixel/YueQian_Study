/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-11 19:39:35
 * @LastEditTime: 2021-08-13 14:48:49
 * @LastEditors: ZhouGuiqing
 * @Description: 编写一个像素坏点检测程序，在开发板LCD上每隔一秒轮流显示红、绿、蓝三原色
 * @FilePath: \YueQian\code\Experiment\IO\exp4\exp4_1.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>

int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("打开LCD失败");
        return 0;
    }

    char *mm_lcd = mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (mm_lcd == NULL)
    {
        perror("映射内存失败");
        return 0;
    }
    bzero(mm_lcd, 800*480*4);
    
    int color[3] = {0x00FF0000, 0x0000FF00, 0x000000FF};//红绿蓝
    for (int i = 0, j = 0; i < 800*480; i++)
    {
        memcpy(mm_lcd+4*i, &color[j%3], 4);
        if (i == 800*480 -1)
        {
            i = 0;
            j++;
            sleep(1);
        }
        
    }
    
    return 0;
}
