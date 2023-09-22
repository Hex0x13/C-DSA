#include <stdio.h>
#include <stdlib.h>

void qsort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int min = i, temp = array[i];
        for (int j = i + 1; j < n; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }
        array[i] = array[min];
        array[min] = temp;
    }
}

int main()
{
    int array[] = {4, 31, 2, 4, 9, 0, 3, 65, 90, 45, 34};
    int size = sizeof(array) / sizeof(array[0]);

    qsort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
