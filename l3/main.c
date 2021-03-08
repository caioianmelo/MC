#include "q1.h"
#include "q23.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main() {
	srand(time(NULL));
	int i;

	printf("Q1\n");
	Matrix m = create_matrix();
	print_matrix(m);

	printf("\nQ2_3\n");
	List* first = create_list(rand()%100);
	print_list(first);
	
	for( i = 0; i < 10; ++i) first = add_node_begin(first, rand()%100);
	first = add_node_begin(first, 14);
	first = add_node_begin(first, 14);
	first = add_node_begin(first, 14);
	print_list(first);

	first = remove_node(first, 14);
	if(!first) exit(1);
	print_list(first);
	
	add_node_end(first, rand()%100);
	add_node_end(first, rand()%100);
	add_node_end(first, rand()%100);
	add_node_end(first, rand()%100);
	print_list(first);

	free_list(first);

	return 0;
}
