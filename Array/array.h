#ifndef D_ARRAY_H
#define D_ARRAY_H

typedef struct d_array d_array;

d_array *init();
void destroy(d_array *array);
void append(d_array *array, const int data);
int pop(d_array *array);
void insert(d_array *array, const int index, const int data);
int removeAt(d_array *array, const int index);
int find(d_array *array, int data);
int include(d_array *array, int data);
int *copy_array(d_array *array);
int get(d_array *array, int index);
void set(d_array *array, int index, int data);
void swap_value(d_array *array, int index_a, int index_b);

#endif // D_ARRAY_H
