#include <stdio.h>


int main(int argc, char const *argv[])
{
    /* code */
    char str[] = "Hello";                    
    char *p = str;
    char *s="abcde";
    s+=2;
    printf("%d\n", s);
    // printf("%d\n",sizeof(str));
    int a = 1;
    printf("a:%d\n",++a);
    return 0;
}
