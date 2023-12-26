#include "list.h"
#include <stdio.h>

static void test_long_list(void);

int main()
{
    printf("First output: \n");
    Node *node_1 = NULL;
    node_1 = list_create_node(8);
    list_out(node_1);

    printf("Second output: \n");
    Node *node_2 = NULL;
    node_2 = list_create_node(45);
    list_insert(node_1, node_2);
    list_out(node_1);

    printf("Third output: \n");
    list_delete_node(node_2);
    list_out(node_1);

    list_delete(node_1);

    test_long_list();

    return 0;
}

static void test_long_list(void)
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
}
