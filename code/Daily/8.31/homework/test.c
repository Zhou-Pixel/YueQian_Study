/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-31 16:33:39
 * @LastEditTime: 2021-08-31 17:05:00
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.31/homework/test.c
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "queue_homework.h"






int main(int argc, char const *argv[])
{
    Node *head = initlist();


    FILE *fp = fopen("./order.txt", "r");

    char buf[100];

    for (int i = 0; i < 2; i++)
    {
        bzero(&buf, sizeof(buf));
        fgets(buf, sizeof(buf), fp);
        add_note(head, create_node(strtok(buf, "\n")));
    }

    while(1)
    {

        bzero(&buf, sizeof(buf));
        char *temp = fgets(buf, sizeof(buf), fp);
        
        if(temp == NULL)
        {
            break;
        }

        add_note(head, create_node(strtok(buf, "\n")));
        remove_node(head);

        system("clear");
        show_queue(head);
    
        sleep(3);
    }



    fclose(fp);
    destroyall(head);

    return 0;
}
