#include <stdlib.h>
#include <stdio.h>

int global_var;

int main() {
	int local_var;
	int* heap_var_pt = (int*)malloc(sizeof(int));

	printf("Memory addr of local variable: %p\n", (void*)&local_var);
	printf("Memory addr of global variable: %p\n", (void*)&global_var);
	printf("Memory addr of heap variable: %p\n", (void*)heap_var_pt);
	printf("Memory addr of main(): %p\n", (void*)&main);

	free(heap_var_pt);
}
