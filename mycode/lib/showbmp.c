/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-12 16:33:09
 * @LastEditTime: 2021-08-21 10:52:03
 * @LastEditors: ZhouGuiqing
 * @Description:自动缩放和居中显示bmp图片 
 * @FilePath: \YueQian\mycode\lib\showbmp.c
 */
#include "showerror.h"
#include "bmp.h"

int showbmp(const char *bmp)
{
    int bmp_fd =open(bmp, O_RDWR);
    if (bmp_fd == -1)
    {
        return OPENPICFAILED;
    }
    
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
       return OPENLCDFAILED; 
    }
    
    
    char *mm_lcd = mmap(NULL, 800*480*4*2, PROT_READ|PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (mm_lcd == NULL)
    {
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


    struct bitmap_header header;
    struct bitmap_info info;
    // printf("%ld\n", sizeof(struct bitmap_header) + sizeof(struct bitmap_info));

    //把前面无关rgb的信息先读取掉
    read(bmp_fd, &header, sizeof(struct bitmap_header));
    read(bmp_fd, &info, sizeof(struct bitmap_info));
    //计算是否还存在另一个结构体
    if(info.compression)
    {
        struct rgb_quad q;
        read(bmp_fd, &q, sizeof(struct rgb_quad));
    }

    //计算无效字节
    int n =  (4-((info.width*(info.bit_count/8))%4)) % 4;
    int totalwidth = info.width*3 + n;//n是无效的字节数，而不是像素数

    //计算需要缩放的倍数
    int zoom = 1;
    if (info.width>800 || info.height>480)
    {
        zoom = (info.width/800 > info.height/480 ? info.width/800 : info.height/480)+1;
    }
    // printf("zoom:%d n:%d\n", zoom, n);


    //计算居中显示的坐标
    int x = (800-info.width/zoom)/2;
    int y = (480 - info.height/zoom)/2;
    char *center = mm_lcd + y*800*4+x*4;


    char *buf = calloc(1, totalwidth);

    //开始复制内存
    for (int i = 0, a = 0; a < 480 - y && i < info.height; a++, i+=zoom)
    {
        lseek(bmp_fd, 0-totalwidth*(i+1), SEEK_END);//bmp文件存储的数据顺序是倒着来的，最后一行应该先显示

        read(bmp_fd, buf, totalwidth);
        
        for (int j = 0, b = 0; b < 800 - x && j < info.width; b++, j+=zoom)
        {
            memcpy(center+b*4+a*800*4, buf+j*3, 3);
        }
        
    }

    vinfo.xoffset = 0;
    vinfo.yoffset = 0;
    ioctl(lcd_fd, FBIOPAN_DISPLAY, &vinfo);
    
    // printf("END :%ld\n", lseek(bmp_fd, 0, SEEK_END));
    munmap(mm_lcd, 800*480*4*2);
    free(buf);
    close(bmp_fd);
    close(lcd_fd);

    return SUCCESS;
}
