#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 1000000

int maior(float *v, int n) {
	int i = 1, im = 0;

	for (; i < n; ++i) {
		if(v[im] < v[i]) im = i;
	}

	return im;
}

int main() {
	float v[LENGTH];
	int i = 0;
	srand(time(NULL));

	for (; i < LENGTH; ++i) v[i] = rand();

	printf("Indice do maior = %d\n", maior(v, LENGTH));

	return 0;
}
