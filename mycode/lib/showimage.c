/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-12 18:59:24
 * @LastEditTime: 2021-08-23 15:24:03
 * @LastEditors: ZhouGuiqing
 * @Description: 自动识别显示图片
 * @FilePath: \YueQian\mycode\lib\showimage.c
 */
#include "showimage.h"


int showimage(const char *image)
{

    if (strlen(image) <= 4)
    {
        printf("showimage.c :%d\n", __LINE__);
        return UNKNOWN;
    }
    else if (strstr(image, ".bmp") != NULL && 
                strcmp(image + strlen(image) - 4, strstr(image, ".bmp")) == 0)//加一个非空判断, 防止strcmp段错误
    {
            return showbmp(image);
    }
    else if(strstr(image, ".jpg") != NULL && 
                strcmp(image + strlen(image) - 4, strstr(image, ".jpg")) == 0)
    {
            return showjpeg(image);
    }
    else
    {
        return NOTSUPPORTED;
    }
    
}    
