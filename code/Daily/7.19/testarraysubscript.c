#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // a[i][j] = 100;
            *(a + i)[j] = 100;
            *(*(a + i) + j) = 100;
            printf("%d\n",a[i][j]);
        }
        
    }
    
    return 0;
}
