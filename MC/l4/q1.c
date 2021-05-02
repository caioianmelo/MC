#include <stdio.h>
#include <stdlib.h>
#include "q1.h"
#include <string.h>

Node*
createStack(char* str) {
	Node* f = (Node*) malloc(sizeof(Node));
	strcpy(f->val, str);
	f->next = NULL;

	return f;
}

Node*
pushN(Node* first, char* str) {
	Node* nn = (Node*) malloc(sizeof(Node));
	if (!nn) exit(1);

	strcpy(nn->val, str);
	nn->next = first;
	first = nn;

	return first;
}

Node*
pullN(Node* first) {
	Node* s = first;

	if(first) {
		first = first->next; 
		printf("r: %s\n", s->val);
		free(s);
	}
	else printf("Free stack!\n");

	return first;
}

void
printfStack(Node* first) {
	Node* n = first;

	if(!n) printf("Free stack!");
	else {
		while(n) {
			printf("%s -> ", n->val);
			n = n->next;
		}
		printf("\n");
	}
}

void
freeStack(Node *first) {
	printf("Free:\n");
	while(first) first = pullN(first);
}
