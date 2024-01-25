#include "list.h"
#include <stdio.h>

/*static void test_long_list(void);*/

/*Взаимодействие с программой в реальном времени*/

int choice(void)
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
            //swap(list);
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

            printf("Enter a value for prepend:\t");
            scanf("%d", &k);
            list_prepend(list, k);
            printf("New node added into beginning of list\n"); /*как и с append переделать i переменную для подсчета узлов*/
            break;

        case 6:

            printf("Enter a value for append:\t");
            scanf("%d", &k);
            list_append(list, k);
            printf("New node added into the end of list\n");
            break;

        case 7:

            printf("Enter a value for insert:\t");
            scanf("%d", &k);
            //list_insert_node(list);
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

int main()
{
    choice();
    /*test_long_list();*/

    return 0;
}

/*static void test_long_list(void)
{
    int i;
    Node* head = list_create_node(0);

    printf("%s\n", __FUNCTION__);

    for (i = 0; i < 100; ++i)
        list_append(head, i);

    list_out(head);
}

void test_2(void)
{
    List list;
    list_init(&list);
    list_prepend(&list, ...);
}

void test_3(void)
{
    List* list = list_create();
    list_prepend(list, ...);
}*/
