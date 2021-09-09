#include <stdio.h>

void  get_string(char  **p)
{
    *p = "hello world";//*p就是str，这里把str由指向NULL改成指向 h
}

int main(void)
{
    char *str = NULL;//str指向NULL
    get_string(&str);//把str的值传给p
    printf("%s\n",  str);//由于str指向的目标是h，所以输出的是hello world
}