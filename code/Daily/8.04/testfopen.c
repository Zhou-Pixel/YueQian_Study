//测试fopen函数以a+的模式打开文件时的文件位置

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("c.txt", "a+");
    int a = fseek(fp, -1, SEEK_CUR);
    if(a == -1)
    {
        printf("空白文件不能往前调整文件指针\n");//空白文件往前调整文件指针会失败
    }
    printf("%c\n",fgetc(fp));//测试发现确实是以a+的模式打开文件，文件位置指针会指向最后
    // if(fgetc(fp) != EOF)
    // {
    //     printf("有字符\n");
    // }
    return 0;
}
