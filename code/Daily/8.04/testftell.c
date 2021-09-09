#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("b.txt","w+");
    printf("%d\n",ftell(fp));
    return 0;
}
