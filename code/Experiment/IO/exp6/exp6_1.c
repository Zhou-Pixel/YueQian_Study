/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-16 14:36:10
 * @LastEditTime: 2021-08-16 15:04:07
 * @LastEditors: ZhouGuiqing
 * @Description: 库文件制作
 * @FilePath: \YueQian\code\Experiment\IO\exp6\exp6_1.c
 */

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "exp6_1.h"

int copyregfile(const char *argv1, const char *argv2)
{

    // printf("copyregfile函数启动\n");
    printf("argv1:%s\n", argv1);
    printf("argv2:%s\n", argv2);
    int fd1 = open(argv1, O_RDONLY);
    if (fd1 == -1)
    {
        // perror("argv[1]打开失败");
        return -1;
    }
    
    int fd2 = open(argv2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[100];
    int nread, nwrite;

    while (1)
    {

        while ((nread = read(fd1, buf, 100)) == -1 && errno == EINTR)
            ;
        if (nread == 0)
        {
            break;
        }
        while (nread > 0)
        {
            char *temp = buf;
            while ((nwrite = write(fd2, temp, nread)) == -1 && errno == EINTR)
                ;
            nread -= nwrite;
            temp += nwrite;
        }
    }
    return 0;
    // printf("复制完成\n");
}