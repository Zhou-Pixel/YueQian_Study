/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-11 19:57:15
 * @LastEditTime: 2021-08-16 09:42:31
 * @LastEditors: ZhouGuiqing
 * @Description: 编写一个程序，使得在LCD上显示八个不同的单色色块，并呈逆时针流转显示
 * @FilePath: \code\Experiment\IO\exp4\exp4_2.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>


#define LCDSIZE 800*480*4

int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/ubuntu_lcd", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("打开LCD失败");
        return 0;

    }
    char *mm_lcd = mmap(NULL, LCDSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (mm_lcd == NULL)
    {
        perror("映射内存失败");
        return 0;
    }
    bzero(mm_lcd, LCDSIZE);

    int color[] = {0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FFFF00, 0x00FFFFFF, 0x00FF00FF, 0x0000FFFF,0x00835F0F};


    char *statingp[] = {mm_lcd+200*4, mm_lcd+400*4, mm_lcd+600*4, mm_lcd+240*800*4+600*4, mm_lcd+240*800*4+400*4, mm_lcd+240*800*4+200*4, mm_lcd+240*800*4, mm_lcd};//逆时针
    char *statingp1[] = {mm_lcd, mm_lcd+240*800*4, mm_lcd+240*800*4+200*4, mm_lcd+240*800*4+400*4,mm_lcd+240*800*4+600*4,mm_lcd+600*4, mm_lcd+400*4, mm_lcd+200*4};//顺时针

    for(int b = 0; ; b++)
    {

        for (int a = 0;a < 8; a++)
        {
            for (int i = 0; i < 240; i++)
            {
                for (int j = 0; j < 200; j++)
                {
                    memcpy(statingp1[a%8]+i*800*4+4*j, &color[(a+b%8)%8], 4);
                }
            }

        }
        sleep(1);
    }

    return 0;
}
