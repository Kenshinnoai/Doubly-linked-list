#include "list.h"
#include <stdio.h>

/*static void test_long_list(void);*/

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
