#include <stdio.h>

struct animals//64位系统，m值为8
{
    char dog;//一个char 7个0
    unsigned long cat;//一个unsigned long 占满8个字节
    short pig;//short占两个0,加上一个char,加5个0
    char fox;//总共24个字节
};
// struct str
// {
//     char c; //
//     char b; //两个char一共是4
//     int a;  //4
// };
// struct student
// {
//     char sex;
//     char a;
//     char b;
//     int age;
//     char name[100];
// };
// struct test
// {
//     char sex;
//     short a;
//     int b;
//     long age;

// };


int main(int argc, char const *argv[])
{
    printf("%d\n", sizeof(struct animals));
    return 0;
}
