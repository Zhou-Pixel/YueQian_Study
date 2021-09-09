#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp1 = fopen("a.txt","w");
    FILE *fp2 = fopen("a.txt","a+");
    fseek(fp2, 0, SEEK_SET);
    long count = 0;
    while (1)
    {
        // printf("%d\n",ftell(fp));
        fprintf(fp1, "%c", 'a');
        count++;
        if (fgetc(fp2) != EOF)
        {
            printf("%d\n",ftell(fp2));
            break;
        }
        

        
    }
    
    printf("%ld\n",count);
    // char buf[10];
    // fgets(buf, 10, fp);
    // printf("%d\n",strlen(buf));
    fclose(fp1);
    fclose(fp2);
    return 0;
}
