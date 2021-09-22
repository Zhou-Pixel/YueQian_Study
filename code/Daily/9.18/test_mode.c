/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-18 15:28:44
 * @LastEditTime: 2021-09-18 15:48:46
 * @LastEditors: ZhouGuiqing
 * @Description: 测试掩码
 * @FilePath: /YueQian/code/Daily/9.18/test_mode.c
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    close(open("a.txt", O_CREAT | O_RDONLY, 0777));
    return 0;
}

