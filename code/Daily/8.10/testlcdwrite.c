/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-10 14:06:30
 * @LastEditTime: 2021-08-10 14:26:08
 * @LastEditors: ZhouGuiqing
 * @Description: 6818 lcd屏显示颜色 
 * @FilePath: \code\Daily\8.10\testlcdwrite.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/ubuntu_lcd", O_RDWR);
    char *p = mmap(NULL, 800*480*4, 
                PROT_READ|PROT_WRITE, MAP_SHARED, lcd_fd, 0);

    
    
    if (lcd_fd == -1)
    {
        perror("打开文件失败");
        return 0;
    }

    int green = 0x0000FF00;
    int color[3] = {0x00FF0000, 0x0000FF00, 0x000000FF};


    for (int i = 0, j = 0; i < 800*480; i++)
    {
        memcpy(p+4*i, &color[j%3], 4);
        if (i == 800*480 -1)
        {
            i = 0;
            j++;
            sleep(1);
            
        }
        
    }
    
    close(lcd_fd);
    munmap(p, 800*480);
    return 0;
}
