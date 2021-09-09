/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-09 11:04:15
 * @LastEditTime: 2021-08-24 09:40:51
 * @LastEditors: ZhouGuiqing
 * @Description: 编写一个程序，令其功能尽量向命令 “cp” 靠近。
 * @FilePath: \YueQian\code\Experiment\IO\exp3\exp3_3.c
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

/**
 * @description:  绝对路径
 * @param {char} *absolutepath
 * @param {char} *relativepath
 * @param {char} *name
 * @return {*}
 */
char *linkpath(char *abpath, const char *partpath, char *name)
{
    bzero(abpath, PATH_MAX); //待优化
    sprintf(abpath, "%s%s%s", partpath, "/", name);
    // printf("%s\n", absolutepath);
    return abpath;
}

/**
 * @description: 复制普通文件
 * @param {*}
 * @return {*}
 */
void copyregfile(const char *argv1, const char *argv2)
{

    printf("copyregfile函数启动\n");
    printf("argv1:%s\n", argv1);
    printf("argv2:%s\n", argv2);
    int fd1 = open(argv1, O_RDONLY);
    if (fd1 == -1)
    {
        perror("argv[1]打开失败");
        return;
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
    close(fd1);
    close(fd2);
    printf("复制完成\n");
}

/**
 * @description: 复制文件夹
 * @param {const char} *dire1
 * @param {const char} *dire2
 * @return {*}
 */
void copydirfile(const char *dire1, const char *dire2)
{
    // printf("copydirfile函数启动\n");
    DIR *dir1, *dir2;
    // printf("dire1:%s\n", dire1);
    // printf("dire2:%s\n", dire2);
    if ((dir1 = opendir(dire1)) == NULL)
    {
        perror("打开argv[1]失败");
        return;
    }

    if ((dir2 = opendir(dire2)) == NULL)
        mkdir(dire2, 0755);

    struct dirent *ep1;

    char *abpath = calloc(1, PATH_MAX);

    while ((ep1 = readdir(dir1)) != NULL)
    {
        if ((strcmp(ep1->d_name, ".") && strcmp(ep1->d_name, "..")))
        {
            continue;
        }
        struct stat info;
        bzero(&info, sizeof(struct stat));
        stat(linkpath(abpath, dire1, ep1->d_name), &info); //待修改

        if (S_ISDIR(info.st_mode))
        {
            char *buf1 = calloc(1, PATH_MAX);//待优化
            char *buf2 = calloc(1, PATH_MAX);
            strcpy(buf1, linkpath(abpath, dire1, ep1->d_name));
            strcpy(buf2, linkpath(abpath, dire2, ep1->d_name));
            copydirfile(buf1, buf2);
            free(buf1);
            free(buf2);
        }
        else
        {
            char *buf1 = calloc(1, PATH_MAX);//待优化
            char *buf2 = calloc(1, PATH_MAX);
            strcpy(buf1, linkpath(abpath, dire1, ep1->d_name));
            strcpy(buf2, linkpath(abpath, dire2, ep1->d_name));
            copyregfile(buf1, buf2); 
            free(buf1);
            free(buf2);
        }
    }

    free(abpath);
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("请输入正确的参数\n");
        return 0;
    }
    struct stat info;
    bzero(&info, sizeof(struct stat));
    stat(argv[1], &info);

    if (S_ISDIR(info.st_mode))
    {
        copydirfile(argv[1], argv[2]);
    }
    else
    {
        copyregfile(argv[1], argv[2]);
    }
    return 0;
}
