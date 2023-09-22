#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define SIZE 5

int main()
{
	d_array *array = init();
	for (int i = 0; i < SIZE; i++)
	{
		append(array, i + 1);
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%i, ", get(array, i));
	}
	printf("\n-----------------------------\n");
	swap_value(array, 0, 4);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%i, ", get(array, i));
	}
	destroy(array);
	return 0;
}
