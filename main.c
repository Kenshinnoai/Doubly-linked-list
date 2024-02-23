#include "list.h"
#include <stdio.h>

int choice(List* list)
{
    int sign, num;

    while (1)
    {
        printf("Enter 0 to finish the program\n");

        printf("Enter 1 to prepend node\n");

        printf("Enter 2 to append node\n");

        printf("Enter 3 to delete node\n");

        printf("Enter 4 to delete list\n");

        printf("Enter 5 to display list's values \n");

        printf("Enter 6 to swap two values from list\n\n");


        scanf("%d", &sign);

        switch (sign)
        {
        case 0:

            printf("Program finished\n");

            return 0;

        case 1:

            num = getNumber();
            
            list_prepend(list, num);
            
            
            printf("New node prepended\n\n");
            
            break;

        case 2:

            num = getNumber();
            
            list_append(list, num);


            printf("New node appended\n");
            
            break;

        case 3:

            list_delete_node(list);
            
            break;

        case 4:

            list_delete(list);
            
            
            printf("List is deleted\n");
            
            break;

        case 5:

            printf("List's values:\n");
            
            list_out(list);
            
            break;

        case 6:

            swap(list);
            
            
            printf("List's values are successfully swapped\n");
            
            break;

        default:

            printf("Try again, put there numbers to choose something\n");
            
            break;
        }
    }
}

int main()
{
    List* list = list_create();
    
    
    choice(list);
    
    return 0;
}
