#ifndef MYLIB_H

#define MYLIB_H

#include <stdlib.h>


typedef struct Node Node;

Node *cr_node(int data);

void list_out(Node *head);

void list_delete(Node *head);

Node *node_add_begin(Node *head, int data);

void node_insert(Node* fromlstnod, Node* newnode);

void delete_node (Node* node, Node* head);


#endif
