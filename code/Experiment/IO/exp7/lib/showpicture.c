/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-12 18:59:24
 * @LastEditTime: 2021-08-20 08:56:36
 * @LastEditors: ZhouGuiqing
 * @Description: 自动识别显示图片
 * @FilePath: \YueQian\code\Experiment\IO\exp7\lib\showpicture.c
 */
#include "showpicture.h"


int showimage(const char *picture)
{

    if (strlen(picture) <= 4)
    {
        printf("showimage.c :%d\n", __LINE__);
        return UNKNOWN;
    }
    else if (strstr(picture, ".bmp") != NULL && 
                strcmp(picture + strlen(picture) - 4, strstr(picture, ".bmp")) == 0)//加一个非空判断, 防止strcmp段错误
    {
            return showbmp(picture);
    }
    else if(strstr(picture, ".jpg") != NULL && 
                strcmp(picture + strlen(picture) - 4, strstr(picture, ".jpg")) == 0)
    {
            return showjpeg(picture);
    }
    else
    {
        return NOTSUPPORTED;
    }
    
}    
