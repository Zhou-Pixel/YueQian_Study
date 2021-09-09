#include <stdio.h>
#define AWEEK 7
int main(int argc, char const *argv[])
{
    int date;
    scanf("%d",&date);
    int left = date % AWEEK;//取余计算多少天
    int week = date / AWEEK;//取余计算多少个星期
    printf("%d个星期%d天\n",week,left);
    return 0;
}
