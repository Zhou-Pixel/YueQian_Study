/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-10 15:54:51
 * @LastEditTime: 2021-08-17 19:56:21
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \code\Daily\8.10\showjpeg\jpg.c
 */
#include "jpg.h"

// jpeg格式图片解码套路：
struct imginfo * jpg2rgb(char const *jpgfile)
{
	// 读取图片文件属性信息
	// 并根据其大小分配内存缓冲区jpg_buffer
	struct stat file_info;
	stat(jpgfile, &file_info);
	int fd = open(jpgfile, O_RDONLY);

	unsigned char *jpg_buffer;
	jpg_buffer = (unsigned char *)calloc(1, file_info.st_size);
	int n = read(fd, jpg_buffer, file_info.st_size);
    // printf("jpeg文件大小:%ld\n", file_info.st_size);
    // printf("已经读取的大小: %d\n", n);

	// 声明解码缩结构体，以及错误管理结构体
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	// 使用缺省的出错处理来初始化解码缩结构体
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	// 配置该cinfo，使其从jpg_buffer中读取jpg_size个字节
	// 这些数据必须是完整的JPEG数据
	jpeg_mem_src(&cinfo, jpg_buffer, file_info.st_size);

	// 读取JPEG文件的头，并判断其格式是否合法
	int ret = jpeg_read_header(&cinfo, true);
	if(ret != 1)
	{
		fprintf(stderr, "[%d]: jpeg_read_header failed: "
			"%s\n", __LINE__, strerror(errno));
        return NULL;
	}

	// 开始解码
	jpeg_start_decompress(&cinfo);

    struct imginfo *minfo = calloc(1, sizeof(struct imginfo));
	minfo->width = cinfo.output_width;
	minfo->height = cinfo.output_height;
	minfo->pixel_size = cinfo.output_components;

	int row_stride = minfo->width * minfo->pixel_size;

	// 根据图片的尺寸大小，分配一块相应的内存rgb_buffer
	// 用来存放从jpg_buffer解码出来的图像数据
	unsigned long rgb_size;
	rgb_size = minfo->width *
			minfo->height * minfo->pixel_size;
	minfo->rgb = (char *)calloc(1, rgb_size);

	// 循环地将图片的每一行读出并解码到rgb_buffer中
	int line = 0;
	while(cinfo.output_scanline < cinfo.output_height)
	{
		unsigned char *buffer_array[1];
		buffer_array[0] = minfo->rgb +
				(cinfo.output_scanline) * row_stride;
		jpeg_read_scanlines(&cinfo, buffer_array, 1);
	}

	// 解码完了，将jpeg相关的资源释放掉
 	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	free(jpg_buffer);

	return minfo;
}
