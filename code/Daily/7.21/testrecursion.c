#include <stdio.h>

int judge(int i, int x)
{
    if (x < i)
    {
        return 0;
    }
    else if (x == i)
    {
        return 1;
    }
    return judge(2 * i + 1,x) || judge(3 * i + 1,x);
    // judge(2 * i + 1,x);
    // judge(3 * i + 1,x);

}

int main(int argc, char const *argv[])
{
    int k,x;
    scanf("%d %d",&k,&x);

    if (judge(k, x))
        printf("YES\n");
    else
        printf("NO\n");
        
    return 0;
}
