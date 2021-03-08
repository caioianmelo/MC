#ifndef _Q1_H_
#define _Q1_H_

typedef struct node {
	char val[40];
	struct node *next;
} Node;

Node* createStack(char* str);
Node* pushN(Node* first, char *str);
Node* pullN(Node* first);
void printfStack(Node* first);
void freeStack(Node* first);
	
#endif
