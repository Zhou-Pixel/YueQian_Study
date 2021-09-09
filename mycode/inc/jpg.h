#ifndef _JPG_H
#define _JPG_H

#include <stdio.h>
#include <dlfcn.h>  // 动态加载动态库的头文件：dlopen()、dlsym()
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

#include "jpeglib.h"

// 存储一张图片的基本信息
struct imginfo
{
	char *rgb;
	int width;
	int height;
	int pixel_size;
};

struct imginfo * jpg2rgb(char const *jpgfile);
int showjpeg(const char *);
#endif