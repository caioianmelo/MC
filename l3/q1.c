#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

Matrix
create_matrix() {
	Matrix matrix;
	int i, j;	

	printf("r c: ");
	scanf("%d %d", &matrix.r, &matrix.c);

	matrix.m = (int**) malloc(sizeof(int*)*matrix.r);
	for(i = 0; i < matrix.r; ++i) matrix.m[i] = (int *) malloc(sizeof(int)*matrix.c);

	for(i = 0; i < matrix.r; ++i) {
		for(j = 0; j < matrix.c; ++j) matrix.m[i][j] = i - j;
	}

	return matrix;
}

void
print_matrix(Matrix matrix) {
	int i, j;

	for(i = 0; i < matrix.r; ++i) {
		for(j = 0; j < matrix.c; ++j) printf("%d ", matrix.m[i][j]);

		printf("\n");
		free(matrix.m[i]);
	}

	free(matrix.m);
}
