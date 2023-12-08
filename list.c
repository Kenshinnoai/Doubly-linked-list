#include "list.h"
#include <stdio.h>

struct Node
{
    struct Node* next;
    struct Node* prev;
    int value;
};


Node* cr_node(int data)
{
    Node* somnod;
    somnod = (Node*)malloc(sizeof(Node));
    somnod->prev = NULL;
    somnod->next = NULL;
    somnod->value = data;
    return somnod;
}

void list_out(Node* head)
{
    Node* cur = head;
    while (cur != NULL)
    {
        printf("%d\n", cur->value);
        cur = cur->next;
    }
}


void list_delete(Node* head)
{
    Node* curr = head;
    Node* nextnd = NULL;
    while (curr != NULL)
    {
        nextnd = curr->next;
        free(curr);
        curr = curr->next;
    }
}


void delete_node(Node* node, Node* head)
{
    Node* nextNeeded = node->next;
    Node* prevNeeded = node->prev;
    if (nextNeeded == NULL)
    {
        if (prevNeeded->prev == NULL)
        {
            prevNeeded = head;
        }
        prevNeeded->next = NULL;
    }
    else
    {
        nextNeeded->prev = prevNeeded;
    }

    if (prevNeeded == NULL)
    {
        if (nextNeeded->next == NULL)
        {
            nextNeeded = head;
        }
        nextNeeded->prev = NULL;
    }
    else
    {
        prevNeeded->next = nextNeeded;
    }
}
Node* node_add_begin(Node* head, int data)
{
    Node* l;
    l = (Node*)malloc(sizeof(Node*));
    l = head->prev;
    l->next = head;
    l->prev = NULL;
    l->value = data;
    return l;
}


void node_insert(Node* fromlstnod, Node* newnode)
{
    Node* nextnode = fromlstnod->next;
    newnode->next = nextnode;
    newnode->prev = fromlstnod;
    fromlstnod->next = newnode;
    if (nextnode != NULL)
    {
        nextnode->prev = newnode;
        nextnode->next = NULL;
    }
}