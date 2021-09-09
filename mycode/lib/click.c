/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-20 17:08:23
 * @LastEditTime: 2021-08-21 11:22:54
 * @LastEditors: ZhouGuiqing
 * @Description: touch库
 * @FilePath: \YueQian\mycode\lib\click.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <stdbool.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include "click.h"
/**
 * @description: 触摸板点击识别，有一定的误触范围允许,如果传小于0的参数，将默认将点击整块屏幕都是为可点击范围,shape决定点击范围是矩形还是圆形
 * @param {*}
 * @return {*}
 */
int click(int x, int y, int xdistence, int ydistence, int shape)
{
    int event_fd = open("/dev/input/event0", O_RDWR);
    if (event_fd == -1)
    {
        perror("打开event文件失败");
        return 0;
    }

    while (1)
    {

        int xlast = -1, ylast = -1;
        int xstart = x * (1024 / 800.0), ystart = y * (600 / 480.0);
        xdistence = xdistence * (1024 / 800.0);
        ydistence = ydistence * (600 / 480.0);
        bool xdone;
        bool ydone;
        if (x < 0 || y < 0)
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

        while (1)
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

            if (buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0)
            {
                break;
            }
        }

        if (xlast == -1 || ylast == -1)
        {
            printf("检测到点击操作\n");
            break;
        }
        else if (xlast >= xstart && xlast - xstart < xdistence && ylast >= ystart && ylast - ystart < ydistence && shape == RECTANGLE)
        {
            printf("检测到点击操作\n");
            break;
        }
        else if (abs(xlast - xstart) * abs(xlast - xstart) + abs(ylast - ystart) * abs(ylast - ystart) < xdistence * ydistence && shape == CIRCULAR)
        {
            printf("检测到点击操作\n");
            break;
        }
    }

    close(event_fd);
    return 1;
}


/**
 * @description: 通过指针的方式返回给调用者坐标信息
 * @param {*}
 * @return {*}
 */

void returnclick(int *x, int *y)
{
    int event_fd = open("/dev/input/event0", O_RDWR);
    if (event_fd == -1)
    {
        perror("打开event文件失败");
        return;
    }

    *x = -1;
    *y = -1;
    
    while (1)
    {

        struct input_event buf;
        bzero(&buf, sizeof(buf));
        read(event_fd, &buf, sizeof(buf));


        if (buf.type == EV_ABS)
        {
            if (buf.code == ABS_X)
            {
                // printf("(%d,", buf.value);

                *x = buf.value*(800/1024.0);
            }
            if (buf.code == ABS_Y)
            {
                // printf("%d)\n", buf.value);

                *y = buf.value*(480/600.0);
            }

        }
        if (buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0)
        {
            break;
        }
    }

    close(event_fd);
}