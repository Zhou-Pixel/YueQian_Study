/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-17 10:38:33
 * @LastEditTime: 2021-08-21 15:39:43
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \YueQian\code\Experiment\IO\IOlast\test.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include "font.h"
#include "click.h"
#include "showpicture.h"

#define EXIT      -1
#define DPMAIN    0
#define DPTIME    1
#define DPCHINESE 2

int state = EXIT;

void showbitmap(bitmap *bm, int x, int y, int offset, int who)
{

    static int begin = 1; //用于判断是否清零，静态数据无论调用多少次函数只初始化一次
    // 字体的信息：
    bm->width;
    bm->height;
    bm->byteperpixel;
    bm->map; // 指向RGB数据，没有上下颠倒，也没有一行4字节倍数的约束，就是纯粹的RGB
    int lcd_fd = open("/dev/fb0", O_RDWR);
    char *mm_lcd = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    char *temp_lcd = mm_lcd + 800 * x + 800 * 4 * y;

    // bzero(mm_lcd, 800*480*4);
    if (begin)
    {
        bzero(mm_lcd, 800 * 480 * 4);
        begin = 0;
    }
    else if (who == 1)
    {
        bzero(mm_lcd, 800 * y * 4);
    }

    for (int i = 0, a = 0; i < 480 - y && i < bm->height; a++, i++)
    {
        for (int j = 0, b = 0; j < 800 - x && j < bm->width; b++, j++)
        {

            int widthplus = (offset + b) % bm->width * 4;
            int heightplus = (offset + a) % bm->height * bm->width * 4;
            memcpy(temp_lcd + j * 4 + i * 800 * 4, bm->map + widthplus + heightplus, 4);
        }
    }
    close(lcd_fd);
    munmap(mm_lcd, 800 * 480 * 4);
}

/**
 * @description: 显示时间线程
 * @param {*}
 * @return {*}
 */
void *displaytime(void *f)
{

    while (1)
    {
        bitmap *bm;
        bm = createBitmapWithInit(800, 50, 4, 0x00000000);
        time_t thetime = time(NULL);
        struct tm *Time = localtime(&thetime);
        char timebuf[100];
        strftime(timebuf, 100, "%Y-%m-%d-%A  %p %H:%M:%S", Time);
        fontPrint(f, bm, 0, 0, timebuf, 0xFF090dF7, -100);
        showbitmap(bm, 0, 0, 0, DPTIME);
        sleep(1);
        if (state != DPTIME)
        {
            break;
        }
    }
    return NULL;
}

/**
 * @description: 显示文字线程
 * @param {void} *f
 * @return {*}
 */
void *displayChinese(void *f)
{
    bitmap *bm2 = createBitmapWithInit(800, 430, 4, 0x00000000);
    int fd = open("text.txt", O_RDWR);
    char *buf = malloc(300);
    bzero(buf, 300);
    read(fd, buf, 300);
    //4.把字体输出到输出框中
    fontPrint(f, bm2, 0, 120, buf, 0xFF000000, -100);
    for (int i; state == DPTIME; i++)
    {
        showbitmap(bm2, 0, 50, i * 10, 0);
        sleep(1);
    }
    return NULL;
}


void displayvideo()
{
    system("killall -KILL mplayer");
}

int main(int argc, char const *argv[])
{

    //1.初始化字库
    font *f = fontLoad("./font/zhong.ttf");
    //2.设置字体的大小
    fontSetSize(f, 50);

    pthread_t t;

    while (1)
    {
        showimage("./image/bmp/3.bmp");
        state = DPMAIN;
        while (1)
        {
            if (state != DPTIME && click(0, 0, 400, 240, RECTANGLE))
            {
                state = DPTIME;
                pthread_create(&t, NULL, displaytime, f);
                pthread_create(&t, NULL, displayChinese, f);
            }
            else if (state == DPTIME && click(400, 240, 100, 100, CIRCULAR))
            {
                state = DPMAIN;
                break; //退出
            }
        }
    }

    for (int i = 0;; i++)
    {
        /* code */
    }

    return 0;
}
