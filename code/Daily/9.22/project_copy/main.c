/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-22 18:52:45
 * @LastEditTime: 2021-09-22 20:32:45
 * @LastEditors: ZhouGuiqing
 * @Description: 利用线程池拷贝文件夹
 * @FilePath: /YueQian/code/Daily/9.22/project_copy/main.c
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

#include "thread_pool.h"


typedef struct cp_structure
{
    char *source;
    char *destination;
}filepath;



/**
 * @description: 初始化目标文件和源文件结构体
 * @param {*}
 * @return {*}
 */
filepath *init_cp_structure(void)
{
    filepath *new = calloc(1, sizeof(filepath));
    new->source = calloc(1, 4096);
    new->destination = calloc(1, 4096);

    if (new->destination == NULL || new->source == NULL)
    {
        return NULL;
    }
    return new;
}


void free_cp_structure(filepath *cp)
{
    free(cp->destination);
    free(cp->source);
    free(cp);
}

/**
 * @description:  绝对路径
 * @param {char} *absolutepath
 * @param {char} *relativepath
 * @param {char} *name
 * @return {*}
 */
char *linkpath(char *abpath, const char *partpath, char *name)
{
    bzero(abpath, 4096); //待优化
    sprintf(abpath, "%s%s%s", partpath, "/", name);
    // printf("%s\n", absolutepath);
    return abpath;
}

/**
 * @description: 复制普通文件
 * @param {*}
 * @return {*}
 */
void *copyregfile(void *arg)
{

    // printf("copyregfile函数启动\n");
    // printf("argv1:%s\n", argv1);
    // printf("argv2:%s\n", argv2);
    filepath *copy_files = init_cp_structure();
    memcpy(copy_files, arg, sizeof(filepath));
    int fd1 = open(copy_files->source, O_RDONLY);
    if (fd1 == -1)
    {
        perror("argv[1]打开失败");
        return NULL;
    }

    struct stat stat_buf;
    stat(copy_files->source, &stat_buf);
    
    int fd2 = open(copy_files->destination, O_WRONLY | O_CREAT | O_TRUNC, stat_buf.st_mode);
    char buf[100];
    int nread, nwrite;

    while (1)
    {

        while ((nread = read(fd1, buf, 100)) == -1 && errno == EINTR);
        if (nread == 0)
        {
            break;
        }
        while (nread > 0)
        {
            char *temp = buf;
            while ((nwrite = write(fd2, temp, nread)) == -1 && errno == EINTR);
            nread -= nwrite;
            temp += nwrite;
        }
    }
    free_cp_structure((filepath *)arg);
    free_cp_structure(copy_files);
    close(fd1);
    close(fd2);
    // printf("复制完成\n");
}

/**
 * @description: 复制文件夹
 * @param {const char} *dire1
 * @param {const char} *dire2
 * @return {*}
 */
void copydirfile(thread_pool *copy_pool, filepath *copy_dir)
{
    printf("copydirfile函数启动\n");
    DIR *source, *destination;
    // printf("dire1:%s\n", dire1);
    // printf("dire2:%s\n", dire2);
    if ((source = opendir(copy_dir->source)) == NULL)
    {
        perror("打开argv[1]失败");
        return;
    }

    struct stat stat_buf;
    stat(copy_dir->source, &stat_buf);
    if ((destination = opendir(copy_dir->destination)) == NULL && errno == ENOENT)
        mkdir(copy_dir->destination, stat_buf.st_mode);

    struct dirent *ep;

    char *abpath = calloc(1, 4096);

    while ((ep = readdir(source)) != NULL)
    {
        if ((strcmp(ep->d_name, ".") ==0 || strcmp(ep->d_name, "..") == 0))
        {
            continue;
        }
        struct stat info;
        bzero(&info, sizeof(struct stat));
        stat(linkpath(abpath, copy_dir->source, ep->d_name), &info); //待修改

        if (S_ISDIR(info.st_mode))
        {   
            filepath *new_copy_dir = init_cp_structure();
            linkpath(new_copy_dir->source, copy_dir->source, ep->d_name);
            linkpath(new_copy_dir->destination, copy_dir->destination, ep->d_name);
            copydirfile(copy_pool, new_copy_dir);
        }
        else
        {
            filepath *copy_files = init_cp_structure();
            linkpath(copy_files->source, copy_dir->source, ep->d_name);
            linkpath(copy_files->destination, copy_dir->destination, ep->d_name);
            add_task(copy_pool, copyregfile, copy_files);
        }
    }
    free(copy_dir);
    free(abpath);
}

int main(int argc, char const *argv[])
{
    umask(0);
    if (argc != 3)
    {
        printf("请输入正确的参数\n");
        return 0;
    }
    struct stat info;
    bzero(&info, sizeof(struct stat));
    stat(argv[1], &info);

    thread_pool *copy_pool;


    if(!init_pool(copy_pool, 5))
            return -1;
    

    filepath *copy_files = init_cp_structure();
    strcpy(copy_files->source, argv[1]);
    strcpy(copy_files->destination, argv[2]);


    if (S_ISDIR(info.st_mode))
    {
        copydirfile(copy_pool, copy_files);
    }
    else
    {
        add_task(copy_pool, copyregfile, copy_files);
    }

    destroy_pool(copy_pool);
    return 0;
}

