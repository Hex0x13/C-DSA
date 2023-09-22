#include <stdio.h>
#include <stdlib.h>
#include "../../Array/array.h"

typedef struct MinHeap
{
    int size;
    d_array *array;
} MinHeap;

MinHeap *new_heap()
{
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->array = init();
    heap->size = 0;
    return heap;
}

void destroy_heap(MinHeap *heap)
{
    destroy(heap->array);
    free(heap);
    heap = NULL;
}

int getHeapSize(MinHeap *heap)
{
    return heap->size;
}

int getLeftChildIndex(int parentIndex)
{
    return 2 * parentIndex + 1;
}

int getRightChildIndex(int parentIndex)
{
    return 2 * parentIndex + 2;
}

int getParentIndex(int childIndex)
{
    return (childIndex - 1) / 2;
}

int hasLeftChild(MinHeap *heap, int index)
{
    return getLeftChildIndex(index) < heap->size;
}

int hasRightChild(MinHeap *heap, int index)
{
    return getRightChildIndex(index) < heap->size;
}

int hasParent(int index)
{
    return getParentIndex(index) >= 0;
}

int leftChild(MinHeap *heap, int index)
{
    return get(heap->array, getLeftChildIndex(index));
}

int rightChild(MinHeap *heap, int index)
{
    return get(heap->array, getRightChildIndex(index));
}

int parent(MinHeap *heap, int index)
{
    return get(heap->array, getParentIndex(index));
}

void heapifyDown(MinHeap *heap)
{
    int index = 0;
    while (hasLeftChild(heap, index))
    {
        int smaller = getLeftChildIndex(index);
        if (hasRightChild(heap, index) && rightChild(heap, index) < leftChild(heap, index))
        {
            smaller = getRightChildIndex(index);
        }
        if (get(heap->array, index) < get(heap->array, smaller))
        {
            break;
        }
        else
        {
            swap_value(heap->array, index, smaller);
        }
        index = smaller;
    }
}

void heapifyUp(MinHeap *heap)
{
    int index = heap->size - 1;
    while (hasParent(index) && parent(heap, index) > get(heap->array, index))
    {
        swap_value(heap->array, getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

int peek(MinHeap *heap)
{
    if (heap->size <= 0)
    {
        fprintf(stderr, "Heap is empty");
        return -1;
    }
    return get(heap->array, 0);
}

int poll(MinHeap *heap)
{
    if (heap->size <= 0)
    {
        fprintf(stderr, "Heap is empty");
        return -1;
    }
    int item = get(heap->array, 0);
    set(heap->array, 0, get(heap->array, heap->size - 1));
    heap->size--;
    heapifyDown(heap);
    return item;
}

void offer(MinHeap *heap, int item)
{
    append(heap->array, item);
    heap->size++;
    heapifyUp(heap);
}
