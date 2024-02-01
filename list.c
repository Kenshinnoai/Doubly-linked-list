#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* Объявляет структуру типа Node */
typedef struct Node
{
    struct Node* next;
    struct Node* prev;
    int value;
};

/* Объявляет структуру типа List */
typedef struct List
{
    Node* head;
    Node* tail;
} List;

/* Создает список */
List* list_create(void)
{
    List* list = (List*)malloc(sizeof(List));
    list_init(list);
    return list;
}

/* Проверка на пустоту списка;
 * 1 - если список пуст, 2 - если в списке что-то есть
 * в функцию передаём весь список
 */
int list_is_empty(List* list)
{
    assert(list);

    return list->head == NULL;
}

/* Началу и концу списка присваивается NULL */
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
    //int data;
    //printf("Give the value to put it into new node\t"); ///мб реализовать номера узлов сразу тут?
    //scanf("%d", &data);

    Node* node = (Node*)malloc(sizeof(Node));

    if (node)
    {
        node->prev = NULL;
        node->next = NULL;
        node->value = 0;
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

int list_prepend(List* list, int value)
{
    Node* node = list_create_node();
    if (!node)
        return -1;

    node->value = value;

    if (list->head == NULL)
    {
        assert(list->tail == NULL);
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->prev = NULL;
        node->next = list->head;
        list->head = node;
    }

    return 0;
}

/*Добавление узла в конец списка*/

int list_append(List* list, int value)
{
    Node* node = list_create_node();
    if (!node)
        return -1;

    node->value = value;

    if (list->head == NULL)
    {
        assert(list->tail == NULL);
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->prev = list->tail;
        node->next = NULL;
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
