#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    /* code */
    int fd = open("a.txt",O_RDWR|O_CREAT|O_EXCL);
    int flag = fcntl(fd, F_GETFL);
    flag |= O_NONBLOCK;
    return 0;
}
