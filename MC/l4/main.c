#include "q1.h"
#include "q2.h"
#include "q3_4.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void
randomStr(char *str) {
	int i;

	for(i = 0; i < 39; ++i) str[i] = rand()%('Z'-'A') + 'A'; 
}

void
q1() {
	int i;
	char str[40];
	Node* first;

	randomStr(str);
	first = createStack(str);
	printfStack(first);

	for(i = 0; i < 5; ++i) {
		randomStr(str);
		first = pushN(first, str); 
	}
	printfStack(first);
	printf("--------------------------------------------------------------------------------------------------\n");

	first = pullN(first);
	printfStack(first);
	printf("--------------------------------------------------------------------------------------------------\n");
	first = pullN(first);
	printfStack(first);
	printf("--------------------------------------------------------------------------------------------------\n");

	freeStack(first);
	
}

void
q2() {
	Fifo* fifo = createFifo(rand());	
	int i;
	printfFifo(fifo);
	printf("--------------------------------------------------------------------------------------------------\n");
	
	for(i = 0; i < 5; ++i) addNFifo(fifo, rand());
	printfFifo(fifo);
	printf("--------------------------------------------------------------------------------------------------\n");

	delNFifo(fifo);
	printfFifo(fifo);
	printf("--------------------------------------------------------------------------------------------------\n");
	delNFifo(fifo);
	printfFifo(fifo);
	printf("--------------------------------------------------------------------------------------------------\n");
	delNFifo(fifo);
	printfFifo(fifo);
	printf("--------------------------------------------------------------------------------------------------\n");
	
	freeFifo(fifo);
}

char
randChar() {
	return rand()%('Z'-'A') + 'A';
}

void
q3() {
	char r;
	Tree* t;
	int i;

	r = randChar();
	printf("C: %c\n", r);
	t = createTree(r);
	printfTree(t->first, 0);
	printf("--------------------------------------------------------------------------------------------------\n");

	for(i = 0; i < 10; ++i) { 
		printf("%c, ", r);
		r = randChar();
		addBranch(t->first, r);
	}
	printf("\n");
	printfTree(t->first, 0);
	printf("--------------------------------------------------------------------------------------------------\n");


	r = randChar();
	addBranch(t->first, 'A');
	printfTree(t->first, 0);
	searchChar(t->first, 'A');
	printf("--------------------------------------------------------------------------------------------------\n");

	freeTree(t->first);
	free(t);
}

int
main() {
	char q;
	srand(time(NULL));
	
	printf("Q: ");
	scanf(" %c", &q);

	switch(q) {
		case '1':
			q1();
		break;
		case '2':
			q2();
		break;
		case '3':
			q3();
		break;
	}

	return 0;
}
