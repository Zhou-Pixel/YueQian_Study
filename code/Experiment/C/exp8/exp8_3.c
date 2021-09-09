#include <stdio.h>

struct  customtime
{
    int year;
    int month;
    int date;
};

int main(int argc, char const *argv[])
{
    struct customtime custime;
    printf("输入年月日，以空格隔开\n");
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d %d %d",&custime.year,&custime.month,&custime.date);
    


    if ((custime.year%4 == 0 && custime.year%100 !=0) || custime.year%400 == 0)
    {
        printf("是闰年");
        months[1] = 29;
    }
    if (custime.date<=0 || custime.date > months[custime.month - 1] || custime.month <= 0 || custime.month > 12 )
    {
        printf("错误日期");
        return 0;
    }
    

    int total_date = 0;

    for (int i = 0; i < custime.month; i++)
    {
        total_date += months[i];
    }
    
    total_date += custime.date;
    printf("%d\n",total_date);

    return 0;
}
