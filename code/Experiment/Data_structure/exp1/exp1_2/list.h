/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-24 14:17:17
 * @LastEditTime: 2021-08-24 16:31:40
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \YueQian\code\Experiment\Data_structure\exp1\exp1_2\list.h
 */
typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *initlist();

Node *create_node(int data);


void listheadadd(Node *head, int data);
void listtailadd(Node *head, int data);


Node *removenode(Node *head, int data);
void showlist(Node *);

Node *removepnode(Node *head, Node *rm);