/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-23 17:16:51
 * @LastEditTime: 2021-08-23 17:32:07
 * @LastEditors: ZhouGuiqing
 * @Description: 文件管理器雏形
 * @FilePath: \YueQian\code\Experiment\IO\IOlast\FileExplorer.c
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include "font.h"


int main(int argc, char const *argv[])
{
    font *f = fontLoad("./font/zhong.ttf");
    fontSetSize(f, 50);   
    FILE *fp = fopen("temp.txt", "w+");

    bitmap *bm = createBitmapWithInit(800, 480, 4, 0x00000000);

    DIR *dp = opendir("./text");
    while (1)
    {
        struct dirent *ep = readdir(dp);
        if (ep == NULL)
        {
            break;
        }
        fputs(ep->d_name, fp);
        
    }
    
    


    return 0;
}
