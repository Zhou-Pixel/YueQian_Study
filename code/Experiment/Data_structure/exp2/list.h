/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-24 16:38:55
 * @LastEditTime: 2021-08-24 19:25:17
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp2\list.h
 */
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Node;


Node *initlist();


Node *create_node(int data);

void listheadadd(Node *head, int data);


void listtailadd(Node *head, int data);

Node *removenode(Node *head, int data);

void showlist(Node *head);
void distroyall(Node *head);
