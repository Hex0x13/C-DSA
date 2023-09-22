#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

#define DEFAULT_SIZE 10

typedef struct d_array
{
    int *_array;
    int size;
    int capacity;
} d_array;

d_array *init()
{
    d_array *array = malloc(sizeof(d_array));
    if (array == NULL)
    {
        fprintf(stderr, "Memory Allocation Failed\n");
        return NULL;
    }
    array->capacity = DEFAULT_SIZE;
    array->size = 0;
    array->_array = (int *)malloc(DEFAULT_SIZE * sizeof(int));

    if (array->_array == NULL)
    {
        fprintf(stderr, "Memory Allocation Failed");
        return NULL;
    }
    return array;
}

void destroy(d_array *array)
{
    free(array->_array);
    array->_array = NULL;
    free(array);
    array = NULL;
}

int get(d_array *array, int index)
{
    if (index >= array->size || index < 0)
    {
        fprintf(stderr, "Index Error");
        return -1;
    }
    return array->_array[index];
}

void set(d_array *array, int index, int data)
{
    if (index >= array->size || index < 0)
    {
        fprintf(stderr, "Index Error");
        return;
    }
    array->_array[index] = data;
}

int grow(d_array *array)
{
    int new_capacity = array->capacity + (array->capacity >> 1);
    int *new_array = (int *)realloc(array->_array, sizeof(int) * new_capacity);

    if (new_array == NULL)
    {
        fprintf(stderr, "Memory Reallocation Failed");
        return 0; // Failed
    }

    array->_array = new_array;
    array->capacity = new_capacity;
    return 1; // Success
}

void append(d_array *array, const int data)
{
    if (array->size >= array->capacity)
    {
        if (!grow(array))
            return;
    }
    array->_array[array->size++] = data;
}

int pop(d_array *array)
{
    const int temp = array->_array[array->size - 1];
    array->size--;
    return temp;
}

void insert(d_array *array, const int index, const int data)
{
    if (index >= array->size || index < 0)
    {
        fprintf(stderr, "Index Error");
        return;
    }
    if (array->size >= array->capacity)
    {
        if (!grow(array))
            return;
    }
    for (int i = array->size; i > index; i--)
    {
        array->_array[i] = array->_array[i - 1];
    }
    array->_array[index] = data;
}

int removeAt(d_array *array, const int index)
{
    if (index >= array->size || index < 0)
    {
        fprintf(stderr, "Index Error!");
        return -1;
    }
    const int temp = array->_array[index];
    for (int i = index; i < array->size; i++)
    {
        array->_array[i] = array->_array[i + 1];
    }
    array->size--;
    return temp;
}

int find(d_array *array, int data)
{
    for (int i = 0; i < array->size; i++)
    {
        if (array->_array[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int include(d_array *array, int data)
{
    for (int i = 0; i < array->size; i++)
    {
        if (array->_array[i] == data)
        {
            return 1;
        }
    }
    return 0;
}

int *copy_array(d_array *array)
{
    int *copy = (int *)malloc(sizeof(array->size) * sizeof(int));
    for (int i = 0; i < array->size; i++)
    {
        copy[i] = array->_array[i];
    }
    return copy;
}

void swap_value(d_array *array, int index_a, int index_b)
{
    int temp = array->_array[index_a];
    array->_array[index_a] = array->_array[index_b];
    array->_array[index_b] = temp;
}
