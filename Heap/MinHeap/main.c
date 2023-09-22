#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"

int main()
{
    MinHeap *heap = new_heap();
    offer(heap, 6);
    offer(heap, 1);
    offer(heap, 5);
    offer(heap, 203);
    offer(heap, 32);
    offer(heap, 32);
    int size = getHeapSize(heap);
    printf("SIZE: %i\n\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%i, ", poll(heap));
    }
    printf("\n\nSIZE: %i\n", getHeapSize(heap));
    destroy_heap(heap);
    return 0;
}