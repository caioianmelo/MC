#include <stdio.h>
#include <stdlib.h>
#include "q23.h"

List* 
create_list(int i) {
	List *first = (List*) malloc(sizeof(List));
	if(!first) exit(1);

	first->i = i;
	first->next = NULL;

	return first;
}

List*
add_node_begin(List* f, int i) {
	List *first = (List*) malloc(sizeof(List));
	if(!first) exit(1);
	
	first->i = i;
	first->next = f;

	return first;
}

void
add_node_end(List* f, int i) {
	List *n = f;
	
	while(n->next) n = n->next;

	n->next = (List*) malloc(sizeof(List));
	if(!n) exit(1);
	n->next->i = i;
	n->next->next = NULL;
}

void
print_list(List *f) {
	List *n = f;

	if( !f ) {
		printf("Lista vazia!");
		return;
	}

	while(n) {
		printf("%d -> ", n->i);
		n = n->next;	
	}

	printf("\n");
}

List*
remove_node(List* f, int i) {
	List *n = f, *s = NULL;

	while( n ) {
		if( n->i == i) {
			if( n == f ) {
				s = f;
				f = f->next;
				free(s);
				n = f;
			}
		} 
		else n = n->next;
	}

	return f;
}

void
free_list(List *f) {
	List *r;

	while(f) {
		r = f;
		f = f->next;
		free(r);
	}
}
