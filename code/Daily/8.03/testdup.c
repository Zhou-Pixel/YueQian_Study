#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int fd1 = open("a.txt", O_RDWR|O_CREAT);
    int fd2 = dup(fd1);
    write(fd1, "1243253252352352", 16);
    char s[] = "00000000000000000";
    read(fd2, s, strlen(s));
    printf("%s\n",s);//测试结果显示两个文件描述符共用一套系统资源
    return 0;
}
