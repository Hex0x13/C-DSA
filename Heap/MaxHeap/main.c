#include <stdio.h>
#include <stdlib.h>
#include "max_heap.h"

int main()
{
    MaxHeap *heap = new_maxheap();
    offer(heap, 34);
    offer(heap, 72);
    offer(heap, 1);
    offer(heap, 90);
    offer(heap, 0);
    int size = getMaxHeapSize(heap);
    printf("%i\n", peek(heap));
    printf("%i\n\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%i, ", poll(heap));
    }
    printf("\n\nSIZE: %i\n", getMaxHeapSize(heap));
    destory_maxheap(heap);
    return 0;
}
