#include "servidor.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int s_sock = inicializa_e_espera(7891);
	char buffer[1024], *ep;
	int c = 0;
	long s[2], su;
	
	while (1) {
	      if (recv(s_sock, buffer, 1024, 0)) {
	      	s[c] = strtol(buffer, &ep, 10);
	      	printf("Last number: %ld\n", s[c]);
	      	if(c == 1) {
	      		su = s[0] + s[1];
	      		printf("Sum: %ld\n", su);
	      		c = 0;
	      		(su > 50) ? printf("%ld > 50!\n", su) :
	      			printf("%ld < 50!\n", su);
	      		printf("-----------------------------------------------\n");
	      	} else ++c;
	      }
	}
	
	return 0;
}
