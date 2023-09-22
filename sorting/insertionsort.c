#include <stdio.h>
#include <stdlib.h>

void mergeSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = array[i];
        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

int main()
{
    int array[] = {4, 31, 2, 4, 9, 0, 3, 65, 90, 45, 34};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
