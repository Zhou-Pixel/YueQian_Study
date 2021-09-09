#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MYDELAY 1000*100

int calculation(FILE *fp)
{
    char getname[20];
    int count = 0;
    while (1) //计算名单人数并显示一次名单
    {
        if (fgets(getname, 20, fp) == NULL)
        {
            rewind(fp);
            break;
        }
        // printf("%d\n",strlen(a));
        // a[strlen(a) - 2] = '\0';
        // fflush(stdout);

        // fprintf(stderr, "%s\r", a);
        // usleep(1000 * 6);
        // printf("%s\r", a);
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("打开文件失败\n");
        return 0;
    }
    else
    {

        printf("成功\n");
    }

    char getname[20];
    int count = 0;
    // while (1) //计算名单人数并显示一次名单
    // {
    //     if (fgets(a, 20, fp) == NULL)
    //     {
    //         rewind(fp);
    //         break;
    //     }

    //     // printf("%d\n",strlen(a));
    //     a[strlen(a) - 2] = '\0';
    //     // fflush(stdout);

    //     fprintf(stderr, "%s\r", a);
    //     usleep(1000 * 6);

    //     count++;
    // }

    srand((unsigned)time(NULL));  //随机数的播种
    count = rand()%calculation(fp) + 1; //确定点名的最终号码
    printf("%d\n",count);


    for (int i = 0; i < 10*calculation(fp); i++)
    {
        if (fgets(getname, 20, fp) == NULL)
        {
            rewind(fp);
        }

        getname[strlen(getname) - 1] = '\0';
        fprintf(stderr, "%s\r", getname);
        usleep(MYDELAY);
    }

    rewind(fp);

    for (int i = 1;; i++) //显示最终的结果
    {
        fgets(getname, 20, fp);
        getname[strlen(getname) - 1] = '\0';
        usleep(MYDELAY);
        if (i == count)
        {
            fprintf(stderr, "%s\n", getname);
            break;
        }

        fprintf(stderr, "%s\r", getname);
    }

    fclose(fp);
    return 0;
}
