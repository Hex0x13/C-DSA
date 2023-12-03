#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct LinkedList LinkedList;

void createLinkedList(LinkedList *list);
void destroyLinkedList(LinkedList *list);
void LinkedList_prepend(LinkedList *list, const char *data);
void LinkedList_append(LinkedList *list, const char *data);
const char *LinkedList_removeFirst(LinkedList *list);
const char *LinkedList_removeLast(LinkedList *list);
void LinkedList_traverse(LinkedList *list, const char *_sep);

typedef struct Node
{
    const char *data;
    struct Node *next;
} Node;

Node *createNode(const char *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

typedef struct LinkedList
{
    struct Node *_head;
    struct Node *_tail;
    size_t _size;
} LinkedList;

void createLinkedList(LinkedList *list)
{
    list->_head = NULL;
    list->_tail = NULL;
    list->_size = 0;
}

void destroyLinkedList(LinkedList *list)
{
    Node *ptr = list->_head;
    while (ptr != NULL)
    {
        Node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

void LinkedList_prepend(LinkedList *list, const char *data)
{
    Node *node = createNode(data);
    if (list->_head == NULL)
    {
        list->_head = node;
        list->_tail = node;
    }
    else
    {
        node->next = list->_head;
        list->_head = node;
    }
    list->_size++;
}

void LinkedList_append(LinkedList *list, const char *data)
{
    Node *node = createNode(data);
    if (list->_tail == NULL)
    {
        list->_tail = node;
        list->_head = node;
    }
    else
    {
        list->_tail->next = node;
        list->_tail = list->_tail->next;
    }
    list->_size++;
}

const char *LinkedList_removeFirst(LinkedList *list)
{
    if (list->_head == NULL)
    {
        fprintf(stderr, "LinkedList is empty!\n");
        return NULL;
    }
    else if (list->_head == list->_tail)
    {
        const char *data = list->_head->data;
        free(list->_head);
        list->_head = NULL;
        list->_tail = NULL;
        list->_size--;
        return data;
    }
    else
    {
        const char *data = list->_head->data;
        Node *next = list->_head->next;
        free(list->_head);
        list->_head = next;
        list->_size--;
        return data;
    }
}

const char *LinkedList_removeLast(LinkedList *list)
{
    if (list->_tail == NULL)
    {
        fprintf(stderr, "LinkedList is empty!\n");
        return NULL;
    }
    else if (list->_head == list->_tail)
    {
        const char *data = list->_tail->data;
        free(list->_tail);
        list->_head = NULL;
        list->_tail = NULL;
        list->_size--;
        return data;
    }
    else
    {
        const char *data = list->_tail->data;
        Node *current = list->_head;
        while (current->next != list->_tail)
        {
            current = current->next;
        }
        free(list->_tail);
        current->next = NULL;
        list->_tail = current;
        list->_size--;
        return data;
    }
}

void LinkedList_traverse(LinkedList *list, const char *_sep)
{
    if (_sep == NULL)
    {
        _sep = "\n";
    }

    Node *ptr = list->_head;
    while (ptr != NULL)
    {
        printf("%s%s", ptr->data, _sep);
        ptr = ptr->next;
    }
}

#endif // _LINKED_LIST_H