/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-03 19:40:13
 * @LastEditTime: 2021-08-09 10:43:04
 * @LastEditors: ZhouGuiqing
 * @Description: 用标准IO复制文件
 * @FilePath: \code\Experiment\IO\exp2\exp2_1.c
 */
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    FILE *fp1 = fopen("a.txt", "r");
    FILE *fp2 = fopen("b.txt", "w");
    // struct stat info;
    // stat("a.txt", &info);
    char *buf = calloc(1, 100);
    int nread, nwrite;
    while(1)
    {
        nread = fread(buf, 20, 5, fp1);
        if(nread < 5 && ferror(fp1))
        {
            perror("读取文件出错");
            break;
        }
        if(nread == 0)
        {
            printf("复制完了\n");
            break;

        }

        char *temp = buf;            
        while(nread > 0)
        {


            nwrite = fwrite(temp, 20, nread, fp2);
            nread -= nwrite;
            // printf("%d\n", nread);
            temp += (nwrite*20);
        }




    
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
