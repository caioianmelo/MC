#include "servidor.h"
#include <stdio.h>
#include <stdlib.h>

#define N 1024

int main() {
	int s_sock = inicializa_e_espera(7891);
	char buffer[N];
	
	while (1) {
	      if (recv(s_sock, buffer, N, 0)) {
		      printf("%s\n", buffer);
	     		printf("-----------------------------------------------\n");
	      }
	}
	
	return 0;
}
