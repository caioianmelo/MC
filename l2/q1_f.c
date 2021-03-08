#include <stdio.h>
#include "q1.h"

void
sum (double *args, int n) {
	int i = 0;
	double sum = 0;

	for (; i < n; ++i) sum += args[i];

	printf("Sum = %lf\n", sum);
}

void
mult (double *args, int n) {
	int i = 0;
	double mult = 1;

	for (; i < n; ++i) mult *= args[i];

	printf("Mult = %lf\n", mult);
}

void
division (double *args, int n) {
	int i = 1;
	double div = args[0];

	for (; i < n; ++i) div /= args[i];

	printf("Div = %lf\n", div);
}
