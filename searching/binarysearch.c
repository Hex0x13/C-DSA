#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum DataTypes 
{
    CHAR,
    WCHAR,
    INT,
    SHORT,
    LONG,
    UINT,
    FLOAT,
    DOUBLE,
    PTR,
    PTR_CHAR,
    PTR_INT,
    PTR_FLOAT,
    PTR_DOUBLE
} DataTypes;

unsigned int getDataTypeSize(DataTypes type)
{
    unsigned int size = 0;
    switch (type)
    {
    case CHAR:
        size = sizeof(char);
        break;
    case WCHAR:
        size = sizeof(wchar_t);
        break;
    case INT:
        size = sizeof(int);
        break;
    case SHORT:
        size = sizeof(short);
        break;
    case LONG:
        size = sizeof(long long);
        break;
    case UINT:
        size = sizeof(unsigned int);
        break;
    case FLOAT:
        size = sizeof(float);
        break;
    case DOUBLE:
        size = sizeof(double);
        break;
    case PTR:
        size = sizeof(void *);
        break;
    case PTR_CHAR:
        size = sizeof(char *);
        break;
    case PTR_INT:
        size = sizeof(int *);
        break;
    case PTR_FLOAT:
        size = sizeof(float *);
        break;
    case PTR_DOUBLE:
        size = sizeof(double *);
        break;
    default:
        fprintf(stderr, "ERROR: Unknown data type\n");
        break;
    }
    return size;
}

int find(void *array, size_t numOfElem, DataTypes type, void *item)
{
    size_t sizeOfElem = getDataTypeSize(type);
    size_t start = 0, end = numOfElem - 1;
    size_t mid;
    const char *itemTofind = (const char *)item;
    const char *base = (const char *)array;

    while (start <= end)
    {
        mid = (end - start) / 2 + start;
        const char *midItem = base + mid * sizeOfElem;
        int cmp = *midItem - *itemTofind;

        if (type == FLOAT || type == DOUBLE)
        {
            cmp = *(float *)midItem - *(float *)itemTofind;
        }

        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp > 0)
        {
            end = mid - 1;
        }
        else if (cmp < 0)
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    char array[] = {'a', 'b', 'c', 'd', 'x'};
    size_t arraySize = sizeof(array) / sizeof(array[0]);
    char toFind = 'd';
    int index = find(array, arraySize, CHAR, &toFind);
    printf("%i\n", index);

    int arr2[] = {1, 2, 3, 5, 6, 7, 10};
    size_t ArrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    int tofind2 = 10;
    int index2 = find(arr2, ArrSize2, INT, &tofind2);
    printf("%i\n", index2);

    float arr3[] = {1.8, 2.3, 2.8, 5.9, 6, 6.8, 7};
    size_t ArrSize3 = sizeof(arr3) / sizeof(arr3[0]);
    float tofind3 = 7;
    int index3 = find(arr3, ArrSize3, FLOAT, &tofind3);
    printf("%i\n", index3);

    return 0;
}
