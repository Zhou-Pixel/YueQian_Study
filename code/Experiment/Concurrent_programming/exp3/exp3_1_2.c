/*
 * @Author: ZhouGuiqing
 * @Date: 2021-09-14 19:03:41
 * @LastEditTime: 2021-09-15 10:20:08
 * @LastEditors: ZhouGuiqing
 * @Description: 司机
 * @FilePath: /YueQian/code/Experiment/Concurrent_programming/exp3/exp3_1_2.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>


int status = 0;

void car_start(int signum)
{
    printf("开车\n");
    status = 1;
}
void car_stop(int signum)
{
    printf("停车\n");
    status = 0;
}


void handler_sigint(int signum)
{
    if (access("myfifo", F_OK) == -1)
    {
        mkfifo("myfifo", 0644);
    }
    
    int fd = open("myfifo", O_RDWR);
    if (fd == -1)
    {
        perror("open failed");
        return;
    }
    pid_t pid;
    read(fd, &pid, sizeof(pid));
    kill(pid, SIGRTMIN);
    close(fd);
    exit(0);
}

int main(int argc, char const *argv[])
{
    if (access("myfifo", F_OK) == -1)
    {
        mkfifo("myfifo", 0644);
    }
    
    int fd = open("myfifo", O_RDWR);
    if (fd == -1)
    {
        perror("open failed");
        return 0;
    }


    // char write_buf[100];
    // sprintf(write_buf, "driver:%d", getpid());
    // char read_buf[100];
    // while (1)
    // {
    //     write(fd, write_buf, strlen(write_buf));
    //     bzero(read_buf, sizeof(read_buf));
    //     read(fd, read_buf, sizeof(read_buf));
    //     if (strcmp(read_buf, write_buf))
    //     {
    //         break;
    //     }
    // }
    // pid_t pid;
    // sscanf(read_buf, "conductor:%d", &pid);
    
    pid_t pid = getpid();
    printf("%d\n", pid);
    write(fd, &pid, sizeof(pid));

    signal(SIGRTMIN, car_start);
    signal(SIGRTMAX, car_stop);    
    signal(SIGINT, handler_sigint);
    
    while (1)
    {
        sleep(1);
        switch (status)
        {
        case 1:
            printf("开车中\n");
            break;
        case 0:
            printf("停车中\n");
            break;
        
        }
    }
    
    
    return 0;
}
