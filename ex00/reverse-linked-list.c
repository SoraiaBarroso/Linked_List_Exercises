#include <string.h>
#include <stdlib.h>

/* #ifndef checks if STRUCT_LISTNODE is not defined, 
and if it is not, the struct is defined with the typedef statement.*/

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE

/*typedef statement allows you to use listnode as a type 
rather than having to use struct s_listnode every time.*/

typedef struct s_listnode
{
    int value;
    struct s_listnode* next; //next node reference 
} listnode;
#endif


listnode* reverse_linked_list(listnode* param_1)
{
    listnode *prev_Node = NULL;
    listnode *next_Node = NULL;
    listnode *curr_Node = param_1; 

    while(curr_Node != NULL)
    {   
        //store next
        next_Node = curr_Node->next;
        //reversing current
        curr_Node->next = prev_Node;
        //moving one location ahead
        prev_Node = curr_Node;
        curr_Node = next_Node;
    }
    param_1 = prev_Node;
    return param_1;
}