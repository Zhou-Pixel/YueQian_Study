/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-05 09:29:24
 * @LastEditTime: 2021-08-05 09:42:43
 * @LastEditors: ZhouGuiqing
 * @Description: 测试结构体stat
 * @FilePath: \code\Daily\8.5\teststat.c
 */
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    struct stat info;
    stat(argv[1], &info);
    switch (info.st_mode & S_IFMT)
    {
    case S_IFBLK:
    case S_IFCHR:
        printf("主：%d, 次：%d\n", major(info.st_rdev), minor(info.st_rdev));
        break;
    
    default:
        printf("主：%d, 次：%d\n", major(info.st_dev), minor(info.st_dev));
        break;
    }
    return 0;
}
