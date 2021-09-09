#include <stdio.h>

void rec(int m, int n, int a[][n] ,int b[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
        
    }

}

int main(int argc, char const *argv[])
{

    int m,n;

    printf("%d %d",m,n);
    scanf("%d %d",&m,&n);
    printf("m:%d n:%d\n", m, n);

    int a[m][n];


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 1000;
            // printf("%d\n",a[i][j]);
        }
        
    }
    int b[m][n];
    rec(m, n, a, b);
    printf("-----------------------\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d    ",b[i][j]);
        }
        printf("\n");
        
    }

    return 0;
}
