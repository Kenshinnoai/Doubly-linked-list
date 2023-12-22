#ifndef MYLIB_H
#define MYLIB_H

typedef struct Node Node;

/* Создание элемента списка. */
extern Node* list_create_node(int data);

/* Вставка в начало списка. */
extern Node* list_prepend(Node *head, int data);

/* Вставка в конец списка. */
extern Node* list_append(Node *head, int data);

/* Вставка после insnode. */
extern void list_insert(Node *insnode, Node *newnode);

/* Удаление всего списка. */
extern void list_delete(Node *head);

/* Удаление элемента списка. */
extern void list_delete_node(Node *node);

/* Вывод списка поэлементно на экран. */
extern void list_out(Node *head);

/* Меню для манипуляции функциями через консоль */
extern int choice();

#endif // MYLIB_H
