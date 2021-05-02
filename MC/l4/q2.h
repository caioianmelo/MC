#ifndef _Q2_H_
#define _Q2_H_

typedef struct nodef {
	int val;
	struct nodef* next;
} NodeF;

typedef struct fifo {
	NodeF* first;
	NodeF* last;
} Fifo;

Fifo* createFifo(int val);
Fifo* addNFifo(Fifo* f, int i);
Fifo* delNFifo(Fifo* f);
void printfFifo(Fifo* f);
void freeFifo(Fifo* f);

#endif
