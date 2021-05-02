#ifndef _Q3_4_H
#define _Q3_4_H

typedef struct nodet {
	char ch;
	struct nodet* left;
	struct nodet* right;
} NodeT;

typedef struct tree {
	NodeT* first;
} Tree;

Tree* createTree(char c);
NodeT* addBranch(NodeT* n, char c);
void searchChar(NodeT* n, char c);
void printfTree(NodeT* n, int layer);
void freeTree(NodeT* n);
#endif 
