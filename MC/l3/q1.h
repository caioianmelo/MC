#ifndef _Q1_H
#define _Q1_H

typedef struct matrix{
	int r, c;
	int **m;
} Matrix;

Matrix create_matrix();
void print_matrix(Matrix);

#endif
