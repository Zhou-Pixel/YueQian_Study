#include <stdio.h>
int main(void)
{
    long  a[4] = {1, 2, 3, 4};
    long  *p1=(long *)(&a+1);//&a+1表示是a[3]后面的一个字节的地址，强转为long *后-1相当于减了一个long，8个字节，此时表示的是a[3]
    long  *p2=(long *)((long)a+1);//64位long有8个字节，a是a[0]的地址，被强转为long后是长整型，+1再被强转为long *表示的是a[0]第二个字节开始到a[1]的第一个字节的地址
 
    printf("%lx\n", p1[-1]);//*(p1 - 1)
    printf("%lx\n", *p2);
    
    return 0;
}