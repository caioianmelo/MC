#include <stdio.h>
#include "q1.h"
#include <stdlib.h>

int
main() {
	char op;
	double *args;
	int n, i;

	printf("Nargs op: ");
	scanf("%d %c", &n, &op);
	args = (double *) malloc(sizeof(double)*n);
	
	if(!args) return 1;
	

	for (i = 0; i < n; ++i) {
		printf("arg[%d]: ", i);
		scanf("%lf", &args[i]);
		if (i != 0 && args[i] == 0 && op == 'd') { free(args); return 1; }
	}

	switch(op) {
		case 's':
			sum(args, n);
		break;
		case 'm':
			mult(args, n);
		break;
		case 'd':
			division(args, n);
		break;
	}

	free(args);
	return 0;
}

// Com a utilização de headers podemos modularizar o código, tornando-o mais robusto e fácil de manter e ler devido ao fato de que as funções não precisam mais ficar no mesmo arquivo que as chamam i.e. não sendo necessário copiar o código para cada arquivo que o utiliza.
