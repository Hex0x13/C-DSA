#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    const char *data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    struct Node *head;
    struct Node *tail;
    int size;
} LinkedList;

LinkedList *init()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list; 
}

void destroy(LinkedList *list)
{
    while (list->head != NULL)
    {
        Node *next = list->head->next;
        free(list->head);
        list->head = next;
    }
    free(list->head);
    list->head = NULL;
    free(list->tail);
    list->tail = NULL;
    list->size = 0;
    free(list);
    list = NULL;
}


