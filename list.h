#ifndef MYLIB_H
#define MYLIB_H

typedef struct Node Node;

typedef struct List
{
    Node* head;
    Node* tail;
} List;

/* Создание элемента списка. */
extern Node* list_create_node(int data);

/* Создает пустой список. */
extern List* list_create();

extern void list_init(List* list);

/* Проверяет, пустой ли список. */
extern int list_is_empty(List* list);

/* Вставка в начало списка.
 * Возвращает 0 в случае успеха, либо не ноль в случае ошибки.
 */
extern int list_prepend(List* list, int data);

/* Вставка в конец списка. */
extern Node* list_append(Node *head);

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
