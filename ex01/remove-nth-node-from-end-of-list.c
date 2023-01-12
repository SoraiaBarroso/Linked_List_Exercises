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

//Nth node from the end is (K-N+1)th node from the beginning.

listnode* remove_nth_node_from_end_of_list(listnode* param_1, int param_2)
{
    listnode *temp; //hold address
    listnode *first = param_1; //head of linked list
    listnode *second = param_1; //Nth node from the beginning
    
    for(int i = 0; i < param_2; i++)
    {
        //linked list has fewer than param_2 nodes
        if(second->next == NULL)
        {
            if(i == param_2 - 1)
            {
                temp = param_1;
                param_1 = param_1->next;
                free(temp);
            }
            //returns the original list with the first node removed
            return param_1;
        }
        //advances the second pointer by param_2 nodes
        second = second->next;
    }
  
    //advances both first and second until second becomes NULL. 
    while(second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    //removes the node after first from the list
    temp = first->next;
    first->next = first->next->next;
    free(temp);
    return param_1;
}