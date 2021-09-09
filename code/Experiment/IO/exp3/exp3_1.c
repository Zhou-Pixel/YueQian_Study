/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-05 16:57:17
 * @LastEditTime: 2021-08-05 19:49:24
 * @LastEditors: ZhouGuiqing
 * @Description: 给定一个普通文件，使用尽可能多的方法，获取该文件的大小。
 * @FilePath: \code\Experiment\IO\exp3\exp3_1.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>



/**
 * @description: 用fopen一个字节一个字节读
 * @param {char} *argv
 * @return {*}返回文件大小（字节）
 */
long fopcal(char *argv)
{
    FILE *fp = fopen(argv, "a+");
    char buf[10];
    long count = 0;
    while(1)
    {
        if(fread(buf, 1, 1, fp) == 1)
            count++;
        else
            break;    
        
    }
    fclose(fp);
    return count;
}

/**
 * @description:用系统IO读 
 * @param {*}
 * @return {*}返回文件大小（字节）
 */
long opcal(char *argv)
{
    int fd = open(argv, O_RDONLY);
    char buf[100];
    long sum = 0;
    while(1)
    {
        int count = read(fd, buf, 100);
        if(count == 0)
            break;
        sum += count;
    }
    return sum;
}

/**
 * @description: 用stat结构体的方式读取文件大小
 * @param {*}
 * @return {*}返回文件大小
 */
long statstructcal(char *argv)
{
    struct stat info;
    bzero(&info, sizeof(struct stat));
    stat(argv, &info);
    return info.st_size;
}
/**
 * @description: 以文件位置的方式读取大小
 * @param {*}
 * @return {*}返回文件大小（字节）
 */
long ftellcal(char *argv)
{
    FILE *fp = fopen(argv, "a+");
    
    return ftell(fp);
}
int main(int argc, char const *argv[])
{

    char thefile[20];
    strcpy(thefile, argv[1]);
    // char *thefile = argv[1];
    printf("%ld\n",fopcal(thefile));
    printf("%ld\n",opcal(thefile));
    printf("%ld\n",statstructcal(thefile));
    printf("%ld\n",ftellcal(thefile));
    
    return 0;
}
