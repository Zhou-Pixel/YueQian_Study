#include <stdio.h>

int series(int sum)
{
    if (sum == 1 || sum == 2)
    {
        return 1;
    }
    

    return series(sum - 1) + series(sum - 2);
}

int main(int argc, char const *argv[])
{
    int i;
    scanf("%d",&i);
    printf("%d\n",series(i));
}
