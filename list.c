#include "list.h"
#include <stdio.h>
#include <stdlib.h>


/*Объявляет структуру типа Node*/

struct Node
{
    struct Node* next;
    struct Node* prev;
    int value;
};

/*Объявляет структуру типа List*/
typedef struct List
{
    Node* head;
    Node* tail;
}List;

/*Создает список*/

List* list_create()
{
    List* list = (List*)malloc(sizeof(List));
    list_init(list);
    return list;
};


/*Проверка на пустоту списка;
1 - если список пуст, 2 - если в списке что-то есть
в функцию передаём весь список*/

void list_is_empty(List* list)
{
    Node* node = list->head;
    if (node == NULL)
        printf("Your list is empty\n");
    else
        printf("Your list isn't empty\n");

};


/*Началу и концу списка присваивается NULL*/

void list_init(List* list)
{
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }

};


/*Создаем новый узел*/

Node* list_create_node()
{
    int data;

    printf("Give the value to put it into new node\t");
    scanf("%d", &data);

    Node* node = (Node*)malloc(sizeof(Node));

    if (node)
    {
        node->prev = NULL;
        node->next = NULL;
        node->value = data;
    }

    return node;
};


/*Вывод списка*/

void list_out(List* list)
{
    int i = 0;
    Node* head = list->head;
    while (head)
    {
        printf("node %d: %d\n", i, head->value);
        head = head->next;
    }

};


/*Удаление всего списка*/
void list_delete(List* list)
{
    Node* next = NULL;
    Node* head = list->head;

    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }

};


/*Удаление одного узла*/

void list_delete_node(Node* node)
{
    if (node)
    {
        Node* next = node->next;
        Node* prev = node->prev;

        free(node);

        if (prev)
            prev->next = next;

        if (next)
            next->prev = prev;

    }

};


/*Добавление узла в начало списка*/

int list_prepend(List* list)
{
    Node* node;

    if (!list)
        return 1;

    node = list_create_node();

    if (!node)
        return 2;

    node->next = list->head;
    list->head = node;
};


/*Добавление узла в конец списка*/

int list_append(List* list)
{
    Node* node;

    if (!list)
        return 3;

    node = list_create_node();

    if (!node)
        return 4;

    node->prev = list->tail;
    list->tail = node;
};


/*Вставка узла в список;
insnode - узел из списка, после которого
мы вставляем новый узел*/

void list_insert(Node* insnode, Node* newnode)
{
    newnode->next = insnode->next;
    newnode->prev = insnode;

    insnode->next = newnode;

    if (newnode->next)
        newnode->next->prev = newnode;

};

/*считает и выводит номер удаляемого узла в списке и
удаляет узел по его номеру проходясь по списку*/

void delete_node_by_number(List* list)
{
    int i = 0, k = 0;
    Node* node = list->head;

    list_out(list);

    printf("Give the number of deleting element\t");    /* мб вынести это в отдельную функцию */
    scanf("%d", &i);

    while (node)
    {
        if (k == i)
        {
            list_delete_node(node);
            break;
        }

        k++;
        node = node->next;
    }
};

/*То же самое, что и list_insert, но получает на вход указатель на список*/
void list_insert_node(List* list)
{
    int i;
    Node* newnode = list_create_node();
    Node* head = list->head;

    list_out(list);


    printf("Give the number of element after which you want to insert new node\t");
    scanf("%d", &i);


    for (int k = 0; k < i; k++)
        head = head->next;

    Node* insnode = head;
    list_insert(insnode, newnode);       /* хз какого типа первый аргумент */
};


/*Взаимодействие с программой в реальном времени*/

void choice(void)
{
    int i = 0, k = 0;
    int sign = 1;
    List* list = list_create();

    while (1)
    {
        printf("Enter 0 to finish the program\n");
        printf("Enter 1 to create new node\n");
        printf("Enter 2 to display list's values\n");
        printf("Enter 3 to delete list\n");
        printf("Enter 4 to delete node\n");
        printf("Enter 5 to prepend node\n");
        printf("Enter 6 to append\n");
        printf("Enter 7 to insert node\n");
        printf("Enter 8 to check if list is empty\n\n");

        scanf("%d", &sign);

        switch (sign)
        {
        case 0:

            printf("Program finished\n");
            list_delete(list);
            return 5;

        case 1:

            i++;
            Node* node = list_create_node();
            printf("Node %d created with value %d\n", i, node->value);

            if (node->prev == NULL)    /*Если пред. перед новым узлу узел равен NULL - то на него указывает head*/

                list->head = node;

            else if (!node->next)       /*Если след. после нового узла узел равен NULL - то на него указывает tail*/

                list->tail = node;

            break;

        case 2:

            printf("Your list:\n");
            list_out(list);
            break;

        case 3:

            printf("Are you sure to delete the list? (1 - yes, 0 - no)\t");
            scanf("%d", &k);
            if (k == 1)
                list_delete(list);
            break;


        case 4:

            printf("Are you sure to delete the node? (1 - yes, 0 - no)\t");
            scanf("%d", &k);
            if (k == 1)
                delete_node_by_number(list);
            break;


        case 5:

            list_prepend(list);
            printf("New node added into beginning of list\n");
            break;


        case 6:

            list_append(list);
            printf("New node added into the end of list\n");
            break;

        case 7:

            list_insert_node(list);
            printf("Node is inserted\n");
            break;

        case 8:

            list_is_empty(list);
            break;

        default:

            printf("Try again, put there numbers to choose something\n");
            break;
        }
    }
};
