#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    LinkedList list;
    createLinkedList(&list);
    LinkedList_append(&list, "apple");
    LinkedList_append(&list, "mango");
    LinkedList_prepend(&list, "heyy");
    LinkedList_prepend(&list, "ulgd");

    // LinkedList_removeFirst(&list);
    // LinkedList_removeFirst(&list);
    // LinkedList_removeFirst(&list);
    LinkedList_removeLast(&list);
    LinkedList_removeLast(&list);
    LinkedList_removeLast(&list);
    LinkedList_removeLast(&list);

    LinkedList_traverse(&list, NULL);
    destroyLinkedList(&list);
    return 0;
}
