#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* next;
    struct Node* prev;
    int value;
};

List* list_create()
{
    List* list = (List*)malloc(sizeof(List));
    list_init(list);
    return list;
}

void list_init(List* list)
{
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }
}

Node* list_create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));

    if (node)
    {
        node->prev = NULL;
        node->next = NULL;
        node->value = data;
    }

    return node;
}

void list_out(Node *head)
{
    while (head)
    {
        printf("%d\n", head->value);
        head = head->next;
    }
}

void list_delete(Node *head)
{
    Node* next = NULL;
    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }
}

void list_delete_node(Node *node)
{
    Node* next = node->next;
    Node* prev = node->prev;

    free(node);

    if (prev)
        prev->next = next;

    if (next)
        next->prev = prev;
}

int list_prepend(List* list, int data)
{
    Node* node;

    if (list == NULL)
        return -1;

    node = list_create_node(data);
    if (node == NULL)
        return -1;

    node->next = list->head;
    list->head = node;

    return 0;
}

Node* list_append(Node *head)
{
    int data;
    printf("Enter the number to append\n");
    scanf("%d", &data);
    Node* tail = head;
    Node* node;

    if (!head)
        return NULL;

    /* Ищем конец списка */
    while (tail->next)
        tail = tail->next;

    node = list_create_node(data);

    list_insert(tail, node);

    return node;
}

void list_insert(Node *insnode, Node *newnode)
{
    newnode->next = insnode->next;
    newnode->prev = insnode;

    insnode->next = newnode;

    if (newnode->next)
        newnode->next->prev = newnode;
}

int choice()
{
    int num = 10;
    int i;
    while (num != 0)
    {
         printf("
         scanf("%d", &sign);
		       switch(sign)
		       {
		           case 0:

             printf("Program finished\n");
             return 0;


             case 1:

             i++;
             list_create_node();
             printf("Node %d created", i);
             break;


             case 2:

             printf("Your list:\n");
             list_out();
             break;


             case 3:

             int k;
             printf("Are you sure to delete the list? (1 - yes, 0 - no\t");
             scanf("%d", &k);
             k == 1 ? list_delete(Node *head) : break;
             break;


             case 4:

             int k;
             printf("Are you sure to delete the node? (1 - yes, 0 - no\t");
             scanf("%d", &k);
             k == 1 ? list_delete_node(Node *node) : break;
             break;


             case 5:

             list_prepend(Node *head);
             printf("New node added into beginning of list\n");
             break;


             case 6:

             list_append(Node *head);
             printf("New node added into the end of list\n");
             break;


             case 7:

             list_insert(Node *insnode, Node *newnode);
             printf("Node is inserted\n");
             break;


             default:

             printf("Try again, put there numbers to choose something\n");
             break;
         }
    }
    return 0;
}
