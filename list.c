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
}


/*Проверка на пустоту списка;
1 - если список пуст, 2 - если в списке что-то есть 
в функцию передаём весь список*/   

int list_is_empty(List* list)
{   
    Node* node = list->head;
	if (node == NULL)
	{
		printf("Your list is empty\v");
		return 1;
	}

	else 
	{
		printf("Your list isn't empty\v");
		return 0;
	}

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
}


/*Вывод списка*/            

void list_out(List* list)
{
    int i = 0;
    while (list->head->next)
    {
        printf("node %d: %d\n", i, list->head->value);
        list->head = list->head->next;
    }

}


/*Удаление всего списка*/       
void list_delete(List* list)
{
    Node* next = NULL;

    while (list->head)
    {
        next = list->head->next;
        free(list->head);
        list->head = next;
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

    if (!list)
        return -1;

    node = list_create_node();

    if (!node)
        return -1;

    node->next = list->head;
    list->head = node;

    return 0;
}


/*Добавление узла в конец списка*/      

Node* list_append(List* list)
{
    Node* node;

    if (!list)
        return 0;

    node = list_create_node();

    if (!node)
        return 0; 

    node->prev = list->tail;
    list->tail = node;

    return node;
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
}

void list_insert_using_list(List* list)
{
    int i;
    list_out(list);
    Node* newnode = list_create_node();
    
    printf("Give the number of element after which you want to insert new node\t");
    scanf("%d", &i);

    for(int k = 0; k < i; k++)
    {
        list->head = list->head->next;
    }

    Node* insnode = list->head;
    list_insert(insnode, newnode);       /* хз какого типа первый аргумент */
}


/*Взаимодействие с программой в реальном времени*/

int choice()
{
    int i = 0;
    int sign, k;

    List* list = create_list();
    list_init(list);


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
        printf("Enter 8 to check if list is empty\n");

        scanf("%d", &sign);
        
		if (sign == 0)
        {
            printf("Program finished\n");
            return 0;
        }
        if (sign == 1)  /* недоделано */
        {
            i++;
            printf("Enter the number to put it into new node\n");
            Node* node = list_create_node();
            printf("Node %d created", i);
		
            if (!node->prev)    /*Если пред. перед новым узлу узел равен NULL - то на него указывает head*/
            
                list->head = node; 
                
            else if (!node->next)       /*Если след. после нового узла узел равен NULL - то на него указывает tail*/
            
                list->tail = node; 
                
            /* мб else надо добавить */
            
        }

        if (sign == 2)
        {
            printf("Your list:\n");
            list_out(list);
        }

        if (sign == 3)
        {
            printf("Are you sure to delete the list? (1 - yes, 0 - no)\t");
            scanf("%d", &k);
            if (k == 1)
                list_delete(list);
        }

        if (sign = 4)
        {
            printf("Are you sure to delete the node? (1 - yes, 0 - no)\t");
            scanf("%d", &k);   
            if (k == 1)
                delete_node_by_number(list);
        }

        if (sign == 5)
        {
            printf("Enter number to put it itno new node\t");
            list_prepend(list);
            printf("New node added into beginning of list\n");
        }

        if (sign == 6)
        {    
            printf("Enter number to put into new node\t");
            list_append(list);
            printf("New node added into the end of list\n");
        }

        if (sign == 7)
        {
            list_insert_using_list(list);
            printf("Node is inserted\n");
        }

	if (sign == 8)
        {
            int n = list_is_empty(list);
            if (!n)
                pritnf("Error of displaying list");
        }

        else
        {
            printf("Try again, put there numbers to choose something\n");
        }
        
    }
    return 0;
    
}
