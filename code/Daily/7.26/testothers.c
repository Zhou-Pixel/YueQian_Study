#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <time.h> //用到了time函数 
#include<unistd.h> 
int main(void)
{   
    FILE * dakai=fopen("name.txt","r");
    char b[12][15];
    int ran,data[12]={100};
    int i,j=0;
    int mun;
   printf("请输入您想抽取幸运儿的个数：\n");
        while(fgets(b[i],20,dakai))
        {   
            i++;
            j++;      
        }
    printf("全班最多%d人，请输入%d以内的数：",j,j);      
NN:    scanf("%d",&mun); 
    if(mun>j ||mun<1)
    {
        printf("请您输入有效数字：");
        goto NN;
    }          
    for(i=0;i<12;i++)
     {
        fgets(b[i],20,dakai);
        for(j=0;j<15;j++)
        {
            if(b[i][j]=='\n')
            {b[i][j]='\0';}
        }
        printf("\r%11s",b[i]);
        fflush(stdout);
        usleep((i+1)*80000);
     }


    for(i=0;i<mun;i++)
    {
        if(mun==12)
        {
            for(j=0;j<12;j++)
            {
            printf("\r幸运儿：%s\n",b[j]);  
            }  
            break;
        }
        srand(time(NULL));
MM:        ran=rand()%12;
        for(j=0;j<12;j++)
        {
            if(data[j] == ran)
            {
            goto MM;
            // srand(time(NULL));
            // ran=rand()%12;
            } 
        }
        data[i]=ran;
        sleep(1);       
        printf("\r幸运儿：%s\n",b[ran]);
    } 


}