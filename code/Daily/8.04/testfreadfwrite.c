#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    FILE *fp1 = fopen("8.4.zip", "r+");
    FILE *fp2 = fopen("copy.zip", "w+");

    char *buf = calloc(1, 100);
    if(buf == NULL)
    {
        perror("错误");
        return 0;
    }
    while(1)
    {
        int nread, nwrite;
        long fp1ftell = ftell(fp1);
        while((nread = fread(buf, 20, 5, fp1))<5 && errno == EINTR);
        long fp2ftell = ftell(fp2);
        if(nread == 5)
        {
            while(fwrite(buf, 20, 5, fp2)<5 && errno == EINTR);
        }
        else
        {
            if(feof(fp1))
            {        
                while((nwrite = fwrite(buf, fp1ftell - fp2ftell, 1, fp2))<1 && errno == EINTR);
                break;
            }
            if(ferror(fp2))
            {
                perror("错误");
                break;
            }
        }

        //printf("%ld  %ld", fp1ftell, fp2ftell);
        
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
