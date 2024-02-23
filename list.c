#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node             /* структура, описывающая тип элементов списка */
{

    struct Node* next;
    struct Node* prev;
    int value;

} Node;


typedef struct List             /* структура, описывающая тип списка */
{

    Node* head;
    Node* tail;

} List;


                /* Далее - вспомогательные функции */

/***************************************************************************/



List* list_create(void)                     /* создание списка */
{
    List* list = (List*)malloc(sizeof(List));
    
    list_init(list);
    
    return list;
}


void list_init(List* list)                  /* инициализация списка */
{
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }
}


Node* list_create_node()                    /* создание нового узла */
{

    Node* node = (Node*)malloc(sizeof(Node));

    if (node)
    {
        node->prev = NULL;
        node->next = NULL;
        node->value = 0;
    }
}


int list_is_empty(List* list)               /* проверка на пустоту списка */
{
    assert(list);

    return list->head == NULL;
}


int getNumber()                         /* получение числа от пользователя */
{
    int num;
    
    printf("Enter the value: \t");

    scanf("%d", &num);

    printf("\n");

    return num;
}


 
        /* Далее - функии для взаимодействий с пользователем */

/***************************************************************************/



int list_prepend(List* list, int value)     /* добавление нового узла в начало списка */
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
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    return 0;
}


int list_append(List* list, int value)  /* добавление нового узла в конец списка */
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
        list->tail->next = node;
        list->tail = node;
        node->next = NULL;
    }
    
    return 0;
}


void list_delete_node(List* list)       /* удаление узла из списка */
{
    int num, k = 0;
    Node* node = list->head;

    printf("Enter ID of deleting node\t");

    scanf("%d", &num);


    while (node)
    {
        if (k == num)
        {
            if (node == list->head)
            {
                list->head = node->next;
                
                free(node);
                
            }
            
            else if (node == list->tail)
            {
                list->tail = node->prev;
                
                free(node);
                
            }
            
            else
            {
                if (node->prev != NULL)
                
                    node->prev->next = node->next;


                if (node->next != NULL)
                
                    node->prev->prev = node->prev;


                free(node);
                printf("Node %d deleted\n\n", num);
            }
            
            break;
        }
        
        k++;
        node = node->next;
        
    }
}


void list_delete(List* list)            /* удаление передаваемого списка */
{
    Node* next = NULL;
    Node* head = list->head;

    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }
    
    list->head = list->tail = NULL;
}


void list_out(List* list)               /* вывод всех значений элементов списка */
{
    int i = 0;
    
    Node* head = list->head;

    while (head)
    {
        printf("node %d: %d\n", i, head->value);
        
        head = head->next;
        
        i++;
    }
    
    if (list->head == NULL)
    
        printf("The list is empty\n");
        
    printf("\n");
}


void swap(List* list)                   /* обмен значениями двух элементов списка */ 
{
    int data, n1, n2;
    
    Node* node1 = list->head;
    Node* node2 = list->head;
    
    
    printf("Choose first node to swap\n");
    scanf("%d", &n1);  
    
    
    if (n1 != 0)
    {
        for (int j = 0; j < n1; j++)
            node1 = node1->next;
    }
    
    
    printf("node1 = %d\n", node1->value);
    
    
    printf("Choose second node to swap\n");
    scanf("%d", &n2);
    
    
    if (n2 != 0)
    {
        for (int h = 0; h < n2; h++)
            node2 = node2->next;
    }
    
    
    printf("node2 = %d\n", node2->value);
    
    
    data = node1->value; 
    node1->value = node2->value;
    node2->value = data;
}
