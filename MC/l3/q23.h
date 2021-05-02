#ifndef _Q23_H
#define _Q23_H

typedef struct list{
	int i;
	struct list *next;
} List;

List* create_list(int);
List* add_node_begin(List* first, int i);
void add_node_end(List* first, int i);
void print_list(List* first);
List* remove_node(List* first, int i);
void free_list(List* first);

#endif
