#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    while (1)
    {   
        
        scanf("%d",&input);
        if (input != 0)
        {
            break;
        }
        
    }
    int count = 0;
    while (1)
    {
        if (input%2 == 0)
        {
            input = input/2;
            count++;
        }
        else
        {
            input = 3*input+1;
            count++;

        }
        if (input == 1)
        {
            printf("次数%d\n",count);
            break;
        }
        
        
    }
    
    
    

    return 0;
}
