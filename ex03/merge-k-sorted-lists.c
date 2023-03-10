#include <string.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
    int size;
    listnode **array;
} listnode_array;
#endif

listnode* sort(listnode* first, listnode* second)
{
    listnode* NewNode;

    if(first == NULL)
    {
        return second;
    }
    if(second == NULL)
    {
        return first;
    }
    if(first->val > second->val)
    {
        NewNode = second;
        NewNode->next = sort(first, second->next);
    }
    else{
        NewNode = first;
        NewNode->next = sort(first->next, second);
    }
    return NewNode;
}   

listnode* merge_k_sorted_lists(listnode_array* NodeArray)
{
    listnode* NewNode = NULL;

    for(int i = 0; i < NodeArray->size; i++)
        NewNode = sort(NewNode, NodeArray->array[i]);
    return NewNode;
}