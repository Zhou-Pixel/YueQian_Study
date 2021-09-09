/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-06 18:41:02
 * @LastEditTime: 2021-08-09 19:39:44
 * @LastEditors: ZhouGuiqing
 * @Description:用系统IO复制文件 
 * @FilePath: \code\Experiment\IO\exp1\exp1_1.c
 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int fd1 = open("a.txt", O_RDONLY);
    if (fd1 == -1)
    {
        perror("打开失败");
        return 0;
    }

    int fd2 = open("b.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1)
    {
        perror("打开失败");
        return 0;
    }

    char *buf = calloc(1, 100);
    int nread, nwrite, total = 0;
    while(1)
    {
        while((nread = read(fd1, buf, 100)) == 0 && errno == EINTR);
        if(nread == -1)
        {
            perror("读取出错");
            break;
        }
        else if(nread == 0)
        {
            printf("读完了\n");
            break;
        }
        else if(nread > 0)
        {
            total += nread;
            char *temp = buf;
            while(nread > 0)
            {
                while((nwrite = write(fd2, temp, nread)) == 0 && errno == EINTR);
                nread -= nwrite;
                temp += nwrite;
            }
        }
    }



    printf("Total:%d\n", total);
    close(fd1);
    close(fd2);


    return 0;
}
