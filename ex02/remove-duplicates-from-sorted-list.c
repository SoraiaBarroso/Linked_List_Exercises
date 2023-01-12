#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif


listnode* remove_duplicates_from_sorted_list(listnode* param_1)
{
    listnode *current = param_1; 
    listnode *next_next;

    if(param_1 == NULL)
    {
        return NULL;
    }

    while(current->next != NULL)
    {
        if(current->val == current->next->val)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else{
            current = current->next;
        }
    }
    return param_1;
}