// fread/fwrite 复制文件

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 100*1024

int main(int argc, char const *argv[]) // ./a.out file1 file2
{
    // 打开两个操作文件
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "w");

    // 循环地读取fp1的内容，并写入到fp2中
    char *buf = calloc(1, BUFSIZE);
    if(buf == NULL)
    {
        perror("分配100M内存失败");
        return 0;
    }

    int n;
    long a, b;
    long total = 0; // 记录已经复制了的字节数
    while(1)
    {
        bzero(buf, BUFSIZE);
        a = ftell(fp1);
        while((n=fread(buf, BUFSIZE/5, 5, fp1))<5 && errno==EINTR);

        if(n == 5)
        {
            // 将数据写入到fp2中
            int m;
            while((m=fwrite(buf, BUFSIZE/n, n, fp2))<n && errno==EINTR);

            if(m < n)
            {
                perror("写入数据失败");
                break;
            }

            total += (m*(BUFSIZE/n));
        }

        else
        {
            if(ferror(fp1))
            {
                perror("读取数据失败");
                break;
            }

            if(feof(fp1))
            {
                // 将buf中残留的数据妥善地写入fp2中
                b = ftell(fp1);
                total += fwrite(buf, b-a, 1, fp2);
                break;
            }
        }

        printf("已经复制了%d个字节\n", total);
    }

    fclose(fp1);
    fclose(fp2);
    free(buf);

    return 0;
}