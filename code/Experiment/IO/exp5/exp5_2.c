/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-18 16:52:38
 * @LastEditTime: 2021-08-20 09:57:55
 * @LastEditors: ZhouGuiqing
 * @Description: 编写一个程序，在开发板LCD屏幕上显示一个按钮，支持单击并有按下、弹起的效果
 * @FilePath: \code\Experiment\IO\exp5\exp5_2.c
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
#include <pthread.h>
#include "showpicture.h"



#define AFTER 1
#define BEFORE 0

typedef struct
{
    int x;
    int y;
}coordinate;

static int state = 0;
// void *touch(void *x)
// {
//     int event_fd = open("/dev/input/event0", O_RDWR);
//     if (event_fd == -1)
//     {
//         perror("打开event文件失败");
//         return NULL;
//     }

//     while(1)
//     {

//         int xlast = -1, ylast = -1;
//         int xstart = ((coordinate*)x)->x, ystart = ((coordinate*)x)->y;
//         bool xdone;
//         bool ydone;
//         if (xstart<0 || ystart<0)
//         {
//             xdone = false;
//             ydone = false;
//         }
//         else
//         {
//             xdone = true;
//             ydone = true;
//         }
//         printf("初始化\n");

//         while(1)
//         {
//             struct input_event buf;
//             bzero(&buf, sizeof(buf));
//             read(event_fd, &buf, sizeof(buf));
//             if (buf.type == EV_ABS)
//             {
//                 if (buf.code == ABS_X)
//                 {
//                     printf("(%d,", buf.value);
//                     if (!xdone)
//                     {
//                         xstart = buf.value;
//                         xdone = true;
//                     }
//                     else
//                     {
//                         xlast = buf.value;
//                     }
                    
//                 }
//                 if (buf.code == ABS_Y)
//                 {
//                     printf("%d)\n", buf.value);
//                     if (!ydone)
//                     {
//                         ystart = buf.value;
//                         ydone = true;
//                     }
//                     else
//                     {
//                         ylast = buf.value;
//                     }
//                 }
                
//             }


//             if (buf.type==EV_KEY && buf.code==BTN_TOUCH && buf.value==1)
//             {
//                 state = 1;

//             }
//             if (buf.type==EV_KEY && buf.code==BTN_TOUCH && buf.value==0)
//             {
//                 if (xlast==-1 || ylast==-1)
//                 {
//                     printf("检测到点击操作\n");
//                 }
//                 else if (abs(xlast-xstart)<50 && abs(ylast-ystart)<50)
//                 {
//                     printf("检测到点击操作\n");
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
            
//         }

//     }
    
// }


void *touch2(void *coor)
{
    int event_fd = open("/dev/input/event0", O_RDWR);
    if (event_fd == -1)
    {
        perror("打开event文件失败");
        return NULL;
    }

    int xco = ((coordinate*)coor)->x;
    int yco = ((coordinate*)coor)->y;
    int x, y;
    bool xdone = false;
    bool ydone = false;
    while(1)
    {
        struct input_event buf;
        bzero(&buf, sizeof(buf));

        read(event_fd, &buf, sizeof(buf));

        if (buf.type == EV_ABS)
        {
            if (buf.code == ABS_X && !xdone)
            {
                x = buf.value;
            }
            if (buf.code == ABS_Y && !ydone)
            {
                y = buf.value;
            }
            
        }

        if (buf.type==EV_KEY && buf.code==BTN_TOUCH && buf.value==1)
        {
            if (abs(x-xco) < 50 || abs(y-yco) < 50)
            {
                state = 1;
            }
            continue;   
        }
        if (buf.type==EV_KEY && buf.code==BTN_TOUCH && buf.value==0)
        {
            state = 0;
        }
        
    }
}


int main(int argc, char const *argv[])
{
    coordinate x={400, 240};
    pthread_t t;

    pthread_create(&t, NULL, touch2, &x);
    int image = BEFORE;
    showimage("./image/bmp/beforepress.bmp");
    while(1)
    {
        // if (state == 1 && image != AFTER)
        // {
        //     showimage("./image/bmp/afterpress.bmp");
        // }
        // if (state == 0 && image != BEFORE)
        // {
        //     showimage("./image/bmp/beforepress.bmp");
        // }
        if (image == BEFORE && state == 1)
        {
            showimage("./image/bmp/afterpress.bmp");
            image = AFTER;
        }
        if (image == AFTER && state == 0)
        {
            showimage("./image/bmp/beforepress.bmp");
            image = BEFORE;
        }
        
        
        
    }
    
    return 0;
}
