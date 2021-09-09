/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-17 16:43:10
 * @LastEditTime: 2021-08-20 16:00:32
 * @LastEditors: ZhouGuiqing
 * @Description: 编写一个程序，使得点击一次屏幕，换一种随机颜色。
 * @FilePath: \code\Experiment\IO\exp5\exp5_1.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>    
#include <linux/input.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * @description: 触摸板点击识别，有一定的误触范围允许,如果传小于0的参数，将默认将点击整块屏幕都是为可点击范围
 * @param {*}
 * @return {*}
 */
int touch(int x ,int y)
{
    int event_fd = open("/dev/input/event0", O_RDWR);
    if (event_fd == -1)
    {
        perror("打开event文件失败");
        return 0;
    }

    while(1)
    {

        int xlast = -1, ylast = -1;
        int xstart = x*(1024/800), ystart = y*(600/480);
        bool xdone;
        bool ydone;
        if (x<0 || y<0)
        {
            xdone = false;
            ydone = false;
        }
        else
        {
            xdone = true;
            ydone = true;
        }
        printf("初始化\n");

        while(1)
        {
            struct input_event buf;
            bzero(&buf, sizeof(buf));
            read(event_fd, &buf, sizeof(buf));
            if (buf.type == EV_ABS)
            {
                if (buf.code == ABS_X)
                {
                    printf("(%d,", buf.value);
                    if (!xdone)
                    {
                        xstart = buf.value;
                        xdone = true;
                    }
                    else
                    {
                        xlast = buf.value;
                    }
                    
                }
                if (buf.code == ABS_Y)
                {
                    printf("%d)\n", buf.value);
                    if (!ydone)
                    {
                        ystart = buf.value;
                        ydone = true;
                    }
                    else
                    {
                        ylast = buf.value;
                    }
                }
                
            }


            if (buf.type==EV_KEY && buf.code==BTN_TOUCH && buf.value==0)
            {
                break;
            }
            
        }

        if (xlast==-1 || ylast==-1)
        {
            printf("检测到点击操作\n");
            break;
        }
        else if (abs(xlast-xstart)<50 && abs(ylast-ystart)<50)
        {
            printf("检测到点击操作\n");
            break;
        }

    }


    
    close(event_fd);
    return 1;
    
}


int main(int argc, char const *argv[])
{
    touch(-1, -1);
    return 0;
}
