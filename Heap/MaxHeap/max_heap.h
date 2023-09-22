#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct MaxHeap MaxHeap;
MaxHeap *new_maxheap();
void destory_maxheap(MaxHeap *heap);
int getMaxHeapSize(MaxHeap *heap);
int peek(MaxHeap *heap);
void offer(MaxHeap *heap, int item);
int poll(MaxHeap *heap);

#endif // MAX_HEAP_H