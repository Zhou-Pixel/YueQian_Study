/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-21 16:00:35
 * @LastEditTime: 2021-08-23 17:14:12
 * @LastEditors: ZhouGuiqing
 * @Description: 广播项目
 * @FilePath: \YueQian\code\Experiment\IO\IOlast\broadcast2.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <dirent.h>
#include "font.h"
#include "showimage.h"


struct coordinates
{
    int x;
    int y;
    bool istap;
};


#define EXIT     -1
#define DPMAIN    0
#define DPBC      1
#define DPVIDEO   2
#define DP_PPT    3
 

#define IDTIME    1
#define IDCHAR    0


#define CIRCULAR  1
#define RECTANGLE 0


#define XTRANS   (800/1024.0)
#define YTRANS   (480/600.0)

int state = EXIT;

void bzerolcd()
{

    int lcd_fd = open("/dev/fb0", O_RDWR);
    char *mm_lcd = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);

    bzero(mm_lcd, 800*480*4);

    close(lcd_fd);
    munmap(mm_lcd, 800 * 480 * 4);
}
void showbitmap(bitmap *bm, int x, int y, int offset, int who)
{

    static int begin = 1; //用于判断是否清零，静态数据无论调用多少次函数只初始化一次
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
        bzero(mm_lcd, 800 * 50 * 4);
    }

    for (int i = 0, a = 0; i < 480 - y && i < bm->height; a++, i++)
    {
        for (int j = 0, b = 0; j < 800 - x && j < bm->width; b++, j++)
        {

            int widthplus = (b) % bm->width * 4;
            int heightplus = (offset + a) % bm->height * bm->width * 4;
            memcpy(temp_lcd + j * 4 + i * 800 * 4, bm->map + widthplus + heightplus, 4);
        }
    }
    close(lcd_fd);
    munmap(mm_lcd, 800 * 480 * 4);
}


/**
 * @description: 显示广播信息进程
 * @param {void} *f
 * @return {*}
 */
void *displayChinese(void *f)
{


    // struct stat info;
    // struct dirent ep;
    // DIR *dp = opendir("./text");
    // ep = readdir(dp);
    
    int fd = open("text.txt", O_RDWR);
    char *buf = malloc(300);
    bzero(buf, 300);
    read(fd, buf, 300);

    bitmap *bm = createBitmapWithInit(800, 430, 4, 0x00000000);
    fontPrint(f, bm, 0, 120, buf, 0xFF000000, 800);

    for (int i;; i++)
    {
        if (state != DPBC)
        {
            break;
        }
        showbitmap(bm, 0, 50, i, IDCHAR);

        usleep(100);
    }

    free(bm);
    free(buf);
    close(fd);
    return NULL;
}

void *displaytime(void *f)
{    
    while (1)
    {          
 
        time_t thetime = time(NULL);
        struct tm *Time = localtime(&thetime);
        char timebuf[100];
        strftime(timebuf, 100, "%Y-%m-%d-%A  %p %H:%M:%S", Time);

        bitmap *bm = createBitmapWithInit(800, 50, 4, 0x00000000);
        fontPrint(f, bm, 0, 0, timebuf, 0xFF000000, -100);


        if (state != DPBC)
        {
            free(bm);
            return NULL;
        }
        showbitmap(bm, 0, 0, 0, IDTIME);
 
        sleep(1);
        free(bm);
        
    }
    return NULL;

}

/**
 * @description: 触摸板点击识别，有一定的误触范围允许,如果传小于0的参数，将默认将点击整块屏幕都是为可点击范围,shape决定点击范围是矩形还是圆形
 * @param {*}
 * @return {*}
 */
struct coordinates click(int x, int y, int xdistence, int ydistence, int shape)
{
    
    struct coordinates co;
    bzero(&co, sizeof(co));
    int event_fd = open("/dev/input/event0", O_RDWR);
    if (event_fd == -1)
    {
        perror("打开event文件失败");
        return co;
    }

    
    while (1)
    {

        co.x = -1, co.y = -1;
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
                        xstart = buf.value*(800/1024.0);
                        xdone = true;
                    }
                    else
                    {
                        co.x = buf.value * XTRANS;
                    }
                }
                if (buf.code == ABS_Y)
                {
                    printf("%d)\n", buf.value);
                    if (!ydone)
                    {
                        ystart = buf.value*(480/600.0);
                        ydone = true;
                    }
                    else
                    {
                        co.y = buf.value * YTRANS;
                    }
                }
            }

            if (buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0)
            {
                break;
            }
        }

        if (co.x == -1 || co.y == -1)
        {
            co.x = xstart;
            co.y = ystart;
            printf("检测到点击操作\n");
            break;
        }
        else if (co.x >= xstart && co.x - xstart < xdistence && co.y >= ystart && co.y - ystart < ydistence && shape==RECTANGLE)
        {
            printf("检测到点击操作\n");
            break;
        }
        else if (abs(co.x-xstart) * abs(co.x-xstart) + abs(co.y-ystart) * abs(co.y-ystart) < xdistence * ydistence && shape==CIRCULAR)
        {
            printf("检测到点击操作\n");
            break;
        }
    }

    co.istap = true;
    close(event_fd);
    return co;
}



void displayvideo()
{
    system("killall -KILL mplayer");
    system("mplayer -loop 0 ./media/11.avi  -quiet -slave  &");
}
void *displayppt(void *a)
{
    char *images[] = {"./image/bmp/photo1.bmp", "./image/bmp/photo2.bmp", "./image/bmp/photo3.bmp", "./image/jpg/Forza.jpg"};
    int i = 0;

    while (1)
    {
        if (state != DP_PPT)
        {
            return NULL;
        }
        
        showimage(images[(i++)%4]);
        sleep(1);
        
    }
    
}

int main(int argc, char const *argv[])
{


    font *f = fontLoad("./font/zhong.ttf");
    fontSetSize(f, 50);
    pthread_t t;


    struct coordinates co;
    

    while (1)
    {



        showimage("image/jpg/main.jpg");
        state = DPMAIN;
        co = click(-1, -1, 100, 100, CIRCULAR);
        if (co.x>0 && co.x<400 && co.y>0 && co.y<240)//左上角
        {
            state = DPBC;
            if(pthread_create(&t, NULL, displaytime, f))
                perror("时间线程启动失败：");
            if(pthread_create(&t, NULL, displayChinese, f))
                perror("显示文字线程启动失败："); 
            if (state == DPBC && click(-1, -1, 100, 100, CIRCULAR).istap)
            {
                state = DPMAIN;
                continue;
            } 
        }
        if (co.x>400 && co.x<800 && co.y>0 && co.y<240)//右上角
        {
            state = DPVIDEO;
            displayvideo();
            if (state == DPVIDEO && click(-1, -1, 100, 100, CIRCULAR).istap)
            {
                state = DPMAIN;
                system("killall -2 mplayer");
                continue;
            } 

            
        }
        if (co.x>0 && co.x<400 && co.y>240 && co.y<480)//左下角
        {
            state = DP_PPT;
            pthread_create(&t, NULL, displayppt, NULL);
            if (state == DP_PPT && click(-1, -1, 100, 100, CIRCULAR).istap)
            {
                state = DPMAIN;
                continue;
            } 
            

        }
        if (co.x>400 && co.x<800 && co.y>240 && co.y<480)//右下角
        {
            state = EXIT;
            bzerolcd();
            printf("退出程序\n");
            fontUnload(f);
            return 0;            

        }

    }

    return 0;
}

