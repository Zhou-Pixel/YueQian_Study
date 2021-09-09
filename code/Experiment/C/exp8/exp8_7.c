#include <stdio.h>

void recur(int a[], int k)
{
    if((&a[k -1] - a) <= 1)
        return;

    recur( a+1,  k - 2);//不能写a++,影响后面的a
    int  tmp;
    tmp = a[0];
    // printf("%d\n",tmp);
    a[0] = a[k-1];
    a[k-1] = tmp;
}

int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    recur(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",a[i]);
    }
    
    return 0;
}
