/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-05 16:15:58
 * @LastEditTime: 2021-08-10 14:31:58
 * @LastEditors: ZhouGuiqing
 * @Description: 打开目录文件，并且把目录里面的文件打印出来，隐藏.和..
 * @FilePath: \code\Daily\8.5\testopendir.c
 */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
 int main(int argc, char const *argv[])
 {
     DIR *dp = opendir(argv[1]);
     while(1)
     {
         struct dirent *ep = readdir(dp);
         if(ep == NULL)
         {
             break;
         }
         if(ep->d_name[0] == '.')
            continue;
         printf("%s\n",ep->d_name);
     }
     return 0;
 }
 