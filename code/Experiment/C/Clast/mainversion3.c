#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MYDELAY 1000 * 60
#define MYDELAY2(a) 1000 * (60 + (a))

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

void randomfunc(int countarray[], int num, int all)
{
    srand((unsigned)time(NULL)); //随机数的播种
    for (int i = 0; i < 5; i++)
    {
        countarray[i] = rand() % 20 + 41;
        for (int j = 0; j < i; j++)
        {
            while (countarray[i] == countarray[j])
            {
                countarray[i] = rand() % all + 2 * all + 1;
            }
        }
    }
}



void show(char namelist[][20], int all)
{
    for (int i = 0; i < all; i++)
    {
        srand((unsigned)time(NULL));
        int randomnumber = rand()%all;
        sprintf(stderr,"\r%s",namelist[randomnumber]);
    }
    
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
        printf("打开文件成功\n");
    }

    int N;
    printf("请输入N的值");
    scanf("%d", &N);

    int all = calculate(fp);
    char namelist[all][20];
    char chosenname[all][20];
    int chosennum = 0;

    for (int i = 0; i < all; i++)
    {
        fgets(namelist[i], 20, fp);
    }


    fclose(fp);
    return 0;
}
