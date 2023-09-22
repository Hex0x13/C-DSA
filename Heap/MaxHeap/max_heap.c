#include <stdio.h>
#include <stdlib.h>
#include "../../Array/array.h"

typedef struct MaxHeap
{
    d_array *array;
    int size;
} MaxHeap;

MaxHeap *new_maxheap()
{
    MaxHeap *heap = malloc(sizeof(MaxHeap));
    heap->array = init();
    heap->size = 0;
    return heap;
}

void destory_maxheap(MaxHeap *heap)
{
    destroy(heap->array);
    free(heap);
    heap = NULL;
}

int getMaxHeapSize(MaxHeap *heap)
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

int hasLeftChild(MaxHeap *heap, int index)
{
    return getLeftChildIndex(index) < heap->size;
}

int hasRightChild(MaxHeap *heap, int index)
{
    return getRightChildIndex(index) < heap->size;
}

int hasParent(int index)
{
    return index >= 0;
}

int leftChild(MaxHeap *heap, int index)
{
    return get(heap->array, getLeftChildIndex(index));
}

int rightChild(MaxHeap *heap, int index)
{
    return get(heap->array, getLeftChildIndex(index));
}

int parent(MaxHeap *heap, int index)
{
    return get(heap->array, getParentIndex(index));
}

void heapifyDown(MaxHeap *heap)
{
    int index = 0;
    while (hasLeftChild(heap, index))
    {
        int greaterIndex = getLeftChildIndex(index);
        if (hasRightChild(heap, index) && rightChild(heap, index) > leftChild(heap, index))
        {
            greaterIndex = getRightChildIndex(index);
        }
        if (get(heap->array, index) > get(heap->array, greaterIndex))
        {
            break;
        }
        else
        {
            swap_value(heap->array, index, greaterIndex);
        }
        index = greaterIndex;
    }
}

void heapifyUp(MaxHeap *heap)
{
    int index = heap->size - 1;
    while (hasParent(index) && parent(heap, index) < get(heap->array, index))
    {
        swap_value(heap->array, index, getParentIndex(index));
        index = getParentIndex(index);
    }
}

int peek(MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        fprintf(stderr, "Heap is empty!\n");
        return -1;
    }
    return get(heap->array, 0);
}

void offer(MaxHeap *heap, int item)
{
    append(heap->array, item);
    heap->size++;
    heapifyUp(heap);
}

int poll(MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        fprintf(stderr, "Heap is empty!\n");
        return -1;
    }
    int item = get(heap->array, 0);
    set(heap->array, 0, get(heap->array, heap->size-1));
    heap->size--;
    heapifyDown(heap);
    return item;
}

