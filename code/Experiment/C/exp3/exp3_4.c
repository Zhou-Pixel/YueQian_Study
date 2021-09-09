#include <stdio.h>

int main(int argc, char const *argv[])
{
    // int *p;
    // int a[2][2] = {1, 2, 3, 0};
    // p = a[0];
    // printf("%d, %d", *p, *(p + 1)); // 输出什么？

    

    int *p;
    int a[2][2] = {{1, 0}, {2, 3}};
    p = a[0];
    printf("%d, %d", *p, *(p + 1)); // 输出什么？

    //两段p是a[0][0]的地址，所以*p是a[0][0];*(p+1)是a[0][1];
    //只是两段代码a[0][0],a[0][1]不同而已
    return 0;
}
