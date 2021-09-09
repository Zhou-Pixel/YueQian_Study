/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-05 19:12:33
 * @LastEditTime: 2021-08-10 18:57:33
 * @LastEditors: ZhouGuiqing
 * @Description: 编写一个程序，令其功能向命令 “ls -l” 靠近。
 * @FilePath: \code\Experiment\IO\exp3\exp3_2.c
 */

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

/**
 * @description: 显示文件属性
 * @param {mode_t} st_mode
 * @return {*}
 */
void showmode(mode_t st_mode)
{
    switch (st_mode & S_IFMT) 
    {
    case S_IFBLK:  printf("b");            break;
    case S_IFCHR:  printf("c");            break;
    case S_IFDIR:  printf("d");            break;
    case S_IFIFO:  printf("F");            break;
    case S_IFLNK:  printf("s");            break;
    case S_IFREG:  printf("-");            break;
    case S_IFSOCK: printf("s");            break;
    default:       printf("unknown?\n");   break;      
    }


    for (int i = 0; i < 9; i++)
    {
        char rwx[] = "rwx";
        printf("%c", st_mode & (0x100>>i) ? rwx[i%3] : '-');
    }
    


  
}

/**
 * @description: 把文件具体路径搞出来
 * @param {char} *absolutepath
 * @param {char} *pathname
 * @param {char} *name
 * @return {*}
 */
char *linkpath(char *absolutepath, char *pathname, char *name)
{
    sprintf(absolutepath, "%s%s%s", pathname, "/", name);
    return absolutepath;
}

int main(int argc, char const *argv[])
{
    char *pathname = calloc(1, PATH_MAX);

    DIR *dp;
    switch (argc)
    {
    case 1:
        getcwd(pathname, PATH_MAX);
        dp = opendir(pathname);
        break;
    
    default:
        dp = opendir(argv[1]);
        strcpy(pathname, argv[1]);
        break;
    }

    char *absolutepath = calloc(1, PATH_MAX);
    struct dirent *ep;
    while((ep = readdir(dp)) != NULL)
    {
        if (ep->d_name[0] == '.')
        {
            continue;
        }
        
        struct stat info;
        stat(linkpath(absolutepath, pathname, ep->d_name),&info);
        showmode(info.st_mode);//权限和文件属性
        printf(" ");
        printf("%ld", info.st_nlink);//索引数
        printf(" ");
        printf("%s", getpwuid(info.st_uid)->pw_name);//用户名
        printf(" ");
        printf("%s", getgrgid(info.st_gid)->gr_name);//所属组的名字
        printf(" ");
        printf("%ld", info.st_size);
        printf(" ");
        printf("%s", strtok(ctime(&info.st_atim.tv_sec),"\n"));
        printf(" ");
        printf("%s", ep->d_name);
        printf("\n");
    }


    free(pathname);
    free(absolutepath);
    return 0;
}
