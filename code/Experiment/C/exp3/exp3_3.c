#include <stdio.h>
int main(void)
{
    int a[] = {1, 2, 3, 4};
    int i, *p;
    for(i=0, p=a; i<4; i++, p++)//p存了a[0]的地址 
    {
        printf("%d %d\n", a[i], *p);//输出两个值是一样的
    }
    return 0;
}