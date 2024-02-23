#ifndef MYLIB_H
#define MYLIB_H

typedef struct Node Node;

typedef struct List List;

    /* Далее - вспомогательные функции */

//*******************************************************************

extern List* list_create(void);                     /* создание списка*/

extern void list_init(List* list);                  /* инициализация списка*/

extern Node* list_create_node(void);                /* создание нового узла*/

extern int list_is_empty(List* list);               /* проверка на пустоту списка*/

extern int getNumber();                             /* получение от пользователя числа*/


    /* Далее - фукции для работы с пользователем */

//*******************************************************************


extern int list_prepend(List* list, int value);     /* добавление нового узла в начало списка*/

extern int list_append(List* list, int value);      /* добавление нового узла в конец списка*/

extern void list_delete_node(List *list);           /* удаление узла из списка*/

extern void list_delete(List* list);                /* удаление передаваемого списка*/

extern void list_out(List* list);                   /* вывод всех значений элементов списка*/

extern void swap(List* list);                       /* меняет значения у двух узлов*/

#endif
