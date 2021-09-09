/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-30 15:52:07
 * @LastEditTime: 2021-08-31 16:23:31
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: /code/Daily/8.30/test.c
 */
#include <stdio.h>
#include "stacklist.h"



Node *mergelist(Node *headone, Node *headtwo)
{
    Node *headthree = initlist();

    Node *out_stack1 = removenode(headone);
    Node *out_stack2 = removenode(headtwo);


    while (1)
    {
        printf("第一个%d\n", out_stack1->data);
        printf("第二个%d\n", out_stack2->data);

        if(out_stack1->data > out_stack2->data)
        {
            printf("%d\n", __LINE__);
            addnote(headthree, out_stack1);
            out_stack1 = removenode(headone);
        }
        else
        {
            addnote(headthree, out_stack2);
            out_stack2 = removenode(headtwo);
        }



        if (out_stack1 == NULL)
        {
            while (out_stack2 != NULL)
            {
                addnote(headthree, out_stack2);
                out_stack2 = removenode(headtwo);   
            }
            break;
            
        }
        if (out_stack2 == NULL)
        {
            while (out_stack1 != NULL)
            {
                addnote(headthree, out_stack1);
                out_stack1 = removenode(headone);   
            }
            break;
            
        }
        
    }

    return headthree;
    
}

int main(int argc, char const *argv[])
{
    Node *headone = initlist();

    int a[] = {2, 5, 8, 13, 18};
    int b[] = {1, 3, 4, 7, 9, 10, 19};

    for (int i = 0; i < 5; i++)
    {
        addnote(headone, createnode(a[i]));
    }

    Node *headtwo = initlist();
    for (int i = 0; i < 7; i++)
    {
        addnote(headtwo, createnode(b[i]));
    }

    showlist(headone);
    showlist(headtwo);

    Node *headthree = mergelist(headone, headtwo);
    showlist(headthree);
    destroyall(headthree);
    
    destroyall(headone);

    destroyall(headtwo);
    
    return 0;
}
