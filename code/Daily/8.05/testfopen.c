/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-05 20:08:44
 * @LastEditTime: 2021-09-09 14:33:27
 * @LastEditors: ZhouGuiqing
 * @Description: 验证fopen函数以打开文件的时候，文件位置指针是不是都在开头，但在以a或者a+的模式打开的时候，在第一次读写的时候会立即将文件指针移动到最后，以及以w模式打开文件销毁的问题
 * @FilePath: /code/Daily/8.05/testfopen.c
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp1 = fopen("a.txt", "a+");
    FILE *fp = fopen("a.txt", "w");
    // printf("%ld\n", ftell(fp));//Windows下"a"和"a+"文件位置指针文件一旦打开立即移动到最后
    // fgetc(fp);
    // printf("%ld\n", ftell(fp));//linux下"a"和"a+"文件位置指针在打开之后还是在文件开头，读也不会移动到最后，只有写才会移动到最后
    // fputc(12, fp);
    // printf("%ld\n", ftell(fp));
    getchar();
    
    return 0;
}
