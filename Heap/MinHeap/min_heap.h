#ifndef MIN_HEAP_H
#define MIN_HEAP_H

typedef struct MinHeap MinHeap;

MinHeap *new_heap();
void destroy_heap(MinHeap *heap);
int getHeapSize(MinHeap *heap);
int getLeftChildIndex(int parentIndex);
int getRightChildIndex(int parentIndex);
int getParentIndex(int childIndex);
int hasLeftChild(MinHeap *heap, int index);
int hasRightChild(MinHeap *heap, int index);
int hasParent(int index);
int leftChild(MinHeap *heap, int index);
int rightChild(MinHeap *heap, int index);
int parent(MinHeap *heap, int index);
void heapifyDown(MinHeap *heap);
void heapifyUp(MinHeap *heap);
int peek(MinHeap *heap);
int poll(MinHeap *heap);
void offer(MinHeap *heap, int item);

#endif // MIN_HEAP_H