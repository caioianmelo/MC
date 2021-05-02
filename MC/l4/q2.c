#include "q2.h"
#include <stdio.h>
#include <stdlib.h>

Fifo*
createFifo(int i) {
	Fifo* f = malloc(sizeof(Fifo));
	NodeF* n = malloc(sizeof(NodeF));
	if( !f || !n ) exit(1);

	n->val = i;
	n->next = NULL;

	f->first = n;
	f->last = n;

	return f;
}

Fifo*
addNFifo(Fifo* f, int i) {
	NodeF* n = malloc(sizeof(NodeF));
	if(!n) exit(1);

	n->val = i;
	n->next = NULL;

	if( f->first == f->last ) f->first->next = n;

	f->last->next = n;	
	f->last = n;	

	return f;
}

Fifo*
delNFifo(Fifo* f) {
	NodeF *n = f->first;

	if(n) {
		if( f->first == f->last ) {
			printf("r: %d\n", n->val);
			free(n);
			f->first = NULL;
			f->last = NULL;
		}
		else {
			f->first = n->next;
			printf("r: %d\n", n->val);
			free(n);
		}
	}
	else printf("Empty Fifo!\n");

	return f;
}

void
printfFifo(Fifo* f) {
	NodeF* n = f->first;

	while(n) {
		printf("%d -> ", n->val);
		n = n->next;
	}
	printf("\n");
}

void
freeFifo(Fifo* f) {
	while(f->first) delNFifo(f);
	free(f);
}
