#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int leftArr[], int lsize, int rightArr[], int rsize, int fullArr[])
{
    int l = 0, r = 0, i = 0;
    while (l < lsize && r < rsize)
    {
        if (leftArr[l] > rightArr[r])
        {
            fullArr[i] = rightArr[r];
            r++;
        }
        else
        {
            fullArr[i] = leftArr[l];
            l++;
        }
        i++;
    }

    while (l < lsize)
    {
        fullArr[i] = leftArr[l];
        i++;
        l++;
    }

    while (r < rsize)
    {
        fullArr[i] = rightArr[r];
        i++;
        r++;
    }
}

void qsort(int array[], int n)
{
    if (n <= 1)
        return;
    int mid = n / 2;
    int rsize = n - mid;

    int *leftArr = (int *)malloc(sizeof(int) * mid);
    int *rightArr = (int *)malloc(sizeof(int) * rsize);
    memcpy(leftArr, array, mid * sizeof(array[0]));
    memcpy(rightArr, array + mid, rsize * sizeof(array[0]));
    qsort(leftArr, mid);
    qsort(rightArr, rsize);
    merge(leftArr, mid, rightArr, rsize, array);
    free(leftArr);
    free(rightArr);
}

int main()
{
    int array[] = {4, 31, 2, 9, 0, 3, 65, 90, 45, 34};
    int size = sizeof(array) / sizeof(array[0]);

    qsort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
