#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/mman.h>


int main(int argc, char const *argv[])
{
    int fd = open("a.txt",O_RDWR);
    char *p = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED)
    {
        perror("内存映射失败");
        return 0;
    }


    strncpy(p, "周桂清", 9);
    printf("%s\n",p);

    munmap(p,100);
    close(fd);
    return 0;
}
