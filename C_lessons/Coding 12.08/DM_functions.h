#ifndef DM_functions
#define DM_functions

typedef struct d_array{
	int** arr;
	int capacity;
	int index;
}d_array;



int insert(d_array* array, int* number);
int print_array(d_array* array);
d_array* array_builder (int capacity);
void destroy(d_array* array);

#endif

