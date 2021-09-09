#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MYDELAY(a) 1000 * (a)

int calculate(FILE *fp)
{
    int count = 0;
    char getname[20];
    while (fgets(getname, 20, fp) != NULL)
    {
        count++;
    }
    rewind(fp);
    return count;
}

void randomfunc(int countarray[], int N, int all)//生成随机数组
{
    srand((unsigned)time(NULL));//随机数的播种
    for (int i = 0; i < N; i++)
    {
        countarray[i] = rand() % all +  all;
        for (int j = 0; j < i; j++)
        {
            // while(countarray[i] == countarray[j])
            // {
            //     countarray[i] = rand() % all + 2 * all;
            // }
            if(countarray[i] == countarray[j])
            {
                i--;
                break;
            }
        }
    }

    for (int i = 0; i < N - 1; i++) //冒泡算法
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (countarray[j] > countarray[j + 1])
            {
                int temp = countarray[j];
                countarray[j] = countarray[j + 1];
                countarray[j + 1] = temp;

            }
        }
    }
}

void bettershow(int countarray[], int N, FILE *fp)
{
    char getname[20];
    for (int i = 0, j = 0;j < N; i++)
    {
        if (fgets(getname, 20, fp) == NULL)
        {
            rewind(fp);
            fgets(getname, 20, fp);
        }
        getname[strlen(getname) - 2] = '\0';
        usleep(MYDELAY(i * 10));
        /*
                由于我的txt文件是crlf的，换行的时候字符后面会带\r\n，而lf则只会带\n
            */
        fprintf(stderr, "\r%s", getname);

        if (i == countarray[j])
        {
            j++;
            fprintf(stderr, "\n");
        }
    }
}

// void show(int countarray[], int N, FILE *fp)
// {
//     char getname[20];
//     for (int j = 0; j < N; j++)
//     {
//         for (int i = 0; i < countarray[j]; i++)
//         {
//             if (fgets(getname, 20, fp) == NULL)
//             {
//                 rewind(fp);
//                 fgets(getname, 20, fp);
//             }
//             getname[strlen(getname) - 2] = '\0';
//             usleep(MYDELAY2(i * 1));
//             /*
//                 由于我的txt文件是crlf的，换行的时候字符后面会带\r\n，而lf则只会带\n
//             */
//             fprintf(stderr, "\r%s", getname);
//         }
//         fprintf(stderr, "\n");
//     }
// }

int main(int argc, char const *argv[])
{
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("打开文件失败\n");
        return 0;
    }
    // else
    // {
    //     printf("打开文件成功\n");
    // }



    int all = calculate(fp);
    int N;
    printf("抽取的人数\n");
    //getchar()写在最后，防止输入正确但数值范围不对的整形数据，，导致下面的getchar没有\n读取
    while(!(scanf("%d", &N) == 1 && N > 0 && N <= all && getchar() == '\n'))
    {
        printf("重试\n");
        while(getchar() != '\n');
        
    }
    // printf("%d\n",N);

    int countarray[N];

    randomfunc(countarray, N, all);
    bettershow(countarray, N, fp);

    fclose(fp);
    return 0;
}
