/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-10 15:54:40
 * @LastEditTime: 2021-08-18 20:35:56
 * @LastEditors: ZhouGuiqing
 * @Description: 显示jpeg图片
 * @FilePath: \YueQian\mycode\lib\showjpeg.c
 */
#include <linux/fb.h>
#include "jpg.h"
#include "showerror.h"

int showjpeg(const char *jpeg)
{

    
    struct imginfo *thepic = jpg2rgb(jpeg);
    int lcd_fd = open("/dev/fb0",O_RDWR);
    if (lcd_fd == -1)
    {
        return OPENLCDFAILED;
    }
    
    if (lcd_fd == -1)
    {
        // perror("打开ubuntu_lcd错误");
        return OPENLCDFAILED;
    }

    
    char *mm_lcd = mmap(NULL, 800*480*4*2, PROT_WRITE|PROT_READ, MAP_SHARED, lcd_fd, 0);

    if (mm_lcd == NULL)
    {
        // perror("内存映射失败");
        return MMAPFAILED;   
    }
    bzero(mm_lcd+800*480*4, 800*480*4);
    
    struct fb_var_screeninfo vinfo; // 显卡设备的可变属性结构体
    bzero(&vinfo, sizeof(vinfo));
    vinfo.xoffset = 0;
    vinfo.yoffset = 480;
    if (ioctl(lcd_fd, FBIOPAN_DISPLAY, &vinfo) != 0)
    {
        perror("ioctl失败");
        return IOCTLFAILED;
    }
    

    bzero(mm_lcd, 800*480*4);


    for (int i = 0; i < thepic->width*thepic->height * 3; i++)//把颜色重新排序
    {
        if (((i + 1)%3 == 0) && i != 0)//数组下标从0开始，所以i+1再判断整除
        {
            char temp;
            temp = thepic->rgb[i];
            thepic->rgb[i] = thepic->rgb[i - 2];
            thepic->rgb[i - 2] = temp;
        }
        
    }
    
    int zoom = 1;
    if (thepic->width>800 || thepic->height>480)
    {
        zoom = (thepic->width/800 > thepic->height/480 ? thepic->width/800 : thepic->height/480)+1;
    }

    int x = (800-thepic->width/zoom)/2;
    int y = (480 - thepic->height/zoom)/2;
    char *center = mm_lcd + y*800*4+x*4;

    for (int j=0, b=0; j < thepic->height && b < 480 - x; b++, j+=zoom)
    {
        for (int i=0, a=0; i<thepic->width && a< 800 - y; a++, i+=zoom)
        {
            memcpy(center+4*a+(800*4*b), thepic->rgb+3*i+(thepic->width * 3 * j), 3); 
        }
    }


    
    vinfo.xoffset = 0;
    vinfo.yoffset = 0;
    ioctl(lcd_fd, FBIOPAN_DISPLAY, &vinfo);

    munmap(mm_lcd, 800*480*4*2);
    close(lcd_fd);
    free(thepic->rgb);
    free(thepic);

    
    return SUCCESS;
}
