#ifndef MYLIB_H
#define MYLIB_H

typedef struct Node Node;

typedef struct List List;

/* Создание элемента списка. */
extern Node* list_create_node(void);

/*инициализирует узел списка (присваевает указателям на первый и последний элементы значения NULL)*/
extern void list_init(List* list);

/* Проверяет, пустой ли список. */
extern void list_is_empty(List* list);

/* Вставка в начало списка.
 * Возвращает 0 в случае успеха, либо не ноль в случае ошибки.
 */
extern int list_prepend(List* list);

/* Вставка в конец списка. */
extern int list_append(List* list);

/* Вставка после insnode. */
extern void list_insert(Node* insnode, Node* newnode);

/* Удаление всего списка. */
extern void list_delete(List* list);

/* Удаление элемента списка. */
extern void list_delete_node(Node* node);

/* Вывод списка поэлементно на экран. */
extern void list_out(List* list);


/* Меню для манипуляции функциями через консоль */
extern void choice(void);

/*Ищет номер удаляемого узла в списке, а потом удаляет его*/
extern void delete_node_by_number(List* list);

/*Тот же list_insert, но тут мы передаём в функцию стрктуру list*/
extern void list_insert_using_list(List* list);

#endif // MYLIB_H
