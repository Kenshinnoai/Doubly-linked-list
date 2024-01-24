#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/*Объявляет структуру типа Node*/
typedef struct Node
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
}

/*Проверка на пустоту списка;
1 - если список пуст, 2 - если в списке что-то есть
в функцию передаём весь список*/

void list_is_empty(List* list)
{
    if (list->head == NULL)
        printf("Your list is empty\n");
    else
        printf("Your list isn't empty\n");
}

/*Началу и концу списка присваивается NULL*/

void list_init(List* list)
{
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }
}

/*Создаем новый узел*/

Node* list_create_node()
{
    int data;
    printf("Give the value to put it into new node\t"); ///мб реализовать номера узлов сразу тут?
    scanf("%d", &data);
    Node* node = (Node*)malloc(sizeof(Node));
    if (node)
    {
        node->prev = NULL;
        node->next = NULL;
        node->value = data;
    }
}

void list_out(List* list)
{
    int i = 0;
    Node* head = list->head;

    while (head != NULL)
    {
        printf("node %d: %d\n", i, head->value);    ///бесконечное тк у tail->next нету похоже указателя на null
        head = head->next;
        i++;
    }
}

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
}

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
}

/*Добавление узла в начало списка*/

int list_prepend(List* list)
{
    Node* node;
    node = list_create_node();

    if (list->head == NULL)
        list->head = node;

    if (list->tail = NULL)
        list->tail = node;

    if (list)
    {
        node->next = list->head;
        list->head = node;
    }

    return 0;
}

/*Добавление узла в конец списка*/

int list_append(List* list)
{
    Node* node;
    node = list_create_node();

    if (!node)
        return -1;

    if (!list->head)
        list->head = node; ///может это перенести в создание узла?

    else if (!list->tail)
        list->tail = node;

    if (list)
    {
        node->prev = list->tail;
        list->tail = node;
    }

    return 0;
}

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
}

/*считает и выводит номер удаляемого узла в списке и
удаляет узел по его номеру проходясь по списку*/

void delete_node_by_number(List* list)
{
    int i, k = 0;
    Node* node = list->head;
    list_out(list);
    printf("Give the number of deleting element\t"); /* мб вынести это в отдельную функцию */
    scanf("%d", &i);
    while (node)
    {

        if (k == i)
        {
            if (node == list->head)
                list->head = node->next;

            else if (node == list->tail)
                list->tail = node->prev;


            list_delete_node(node);

            break;
        }

        node = node->next;
        k++;
    }
}

void list_insert_node(List* list)
{
    int i;
    list_out(list);
    Node* newnode = list_create_node();
    Node* head = list->head;

    list_out(list);
    printf("Give the number of element after which you want to insert new node\t");
    scanf("%d", &i);

    for (int k = 0; k < (i - 1); k++)
        head = head->next;

    Node* insnode = head;
    list_insert(insnode, newnode);
}

void swap(List* list)
{
    int data, n1, n2;
    Node* node1 = list->head;
    Node* node2 = list->head;

    printf("Choose first node to swap\n");
    scanf("%d", &n1);

    for (int j = 0; j < n1; j++)
        node1 = node1->next;

    printf("Choose second node to swap\n");
    scanf("%d", &n2);

    for (int h = 0; h < n1; h++)
        node2 = node2->next;

    data = node1->value;
    node1->value = node2->value;
    node2->value = data;

}

/*Взаимодействие с программой в реальном времени*/

int choice()
{
    int i = 0, k = 0;
    int sign = 1;
    List* list = list_create();

    while (1)
    {
        printf("Enter 0 to finish the program\n");
        printf("Enter 1 to swap two nodes\n");
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
            swap(list);
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
            printf("New node added into beginning of list\n"); /*как и с append переделать i переменную для подсчета узлов*/
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
}
