#include "list.h"
#include <stdio.h>


Node *cr_node(int data);

void list_out(Node *head);

void list_delete(Node *head);


Node *node_add_begin(Node *head, int data);


void node_insert(Node* fromlstnod, Node* newnode);


void delete_node (Node* node, Node* head);


int main()
{
    printf("First output: \n");
    Node *node_1 = NULL;
    node_1 = cr_node(8);
    list_out(node_1); 
    printf("Second output: \n");
    Node *node_2 = NULL;
    node_2 = cr_node(45);
    node_insert(node_1, node_2);
    list_out(node_1);
    printf("Third output: \n"); 
    delete_node(node_2, node_1);
    list_out(node_1);
    list_delete(node_1);
    return 0;
}
