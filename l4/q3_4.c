#include "q3_4.h"
#include <stdio.h>
#include <stdlib.h>

Tree*
createTree(char c) {
	Tree* t = malloc(sizeof(Tree));
	NodeT* f = malloc(sizeof(NodeT));
	if(!t || !f) exit(1);

	f->ch = c;
	f->left = NULL;
	f->right = NULL;
	t->first = f;

	return t;
}

NodeT*
addBranch(NodeT* n, char c) {
	if(n) {
		if(n->ch > c) n->left = addBranch(n->left, c);
		else if(n->ch < c) n->right = addBranch(n->right, c);
	}
	else {
		n = malloc(sizeof(NodeT));
		if(!n) exit(1);
		n->ch = c;
		n->left = NULL;
		n->right = NULL;
	}

	return n;
}

void
printfTree(NodeT* n, int layer) {
	if(n) {
		layer++;
		if(n->left) printfTree(n->left, layer);
		if(n->right) printfTree(n->right, layer);
		printf("%d: %c\n", layer, n->ch);
	}
}

void
searchChar(NodeT* n, char c) {
	if(n) {
		if(n->ch == c) printf("%c found!\n", c);
		else {
			if(n->ch > c) searchChar(n->left, c);
			else searchChar(n->right, c);
		}
	}
}

void
freeTree(NodeT* n) {
	if(n) {
		if(n->left) freeTree(n->left);
		if(n->right) freeTree(n->right);
		free(n);
	}
}
