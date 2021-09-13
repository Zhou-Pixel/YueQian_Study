#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>

int daemon_init(void)
{
	int max_fd;
	int i;
	pid_t pid;
	
	/*1，先忽略终端的挂断信号对这个程序的影响*/
	signal(SIGHUP, SIG_IGN);

	/*2，新建一个子进程，让父进程退出，这个时候子进程就不会接收到控制终端的信号跟内容*/
	pid = fork();
	if(pid > 0)
		exit(0);

	/*3，新建一个会话，脱离开原本的会话（也就是这个控制终端）*/
	setsid();

	/*下面的动作都是为了让我们的程序更加的纯净*/

	/*4，新建多一个子进程，脱离开会话管理的权限*/
	pid = fork();
	if(pid > 0)
		exit(0);

	/*5，再让这个子进程脱离开原本的进程组*/
	setpgrp();


	/*6，关闭掉原本的所有文件描述符*/
	max_fd = sysconf(_SC_OPEN_MAX);
	for(i=0; i<max_fd; i++)
		close(i);

	/*7，改变工作路径到根目录*/
	chdir("/");

	/*8，改变原有的掩码，成为没有任何权限影响的0*/
	umask(0);
	

	return 0;
}
