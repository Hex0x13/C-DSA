#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    array[end] = array[i];
    array[i] = pivot;
    return i;
}

void quickSort(int array[], int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}

void q_sort(int array[], int size)
{
    quickSort(array, 0, size - 1);
}

int main()
{
    int array[] = {4, 31, 2, 9, 0, 3, 65, 90, 45, 34};
    int size = sizeof(array) / sizeof(array[0]);

    q_sort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
