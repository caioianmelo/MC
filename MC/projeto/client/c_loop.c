#include "cliente.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void readS_info( char *ip, int *port ) {
	FILE *s_info = fopen("server_info", "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t cread;
	char buffer[15];
	int i = 0;

	if(!s_info) exit(-1);

	for(cread = getline(&line, &len, s_info); cread != -1; cread = getline(&line, &len, s_info)){
		switch(i) {
			case 0:
				memcpy(buffer, line+5, cread-6);
				buffer[cread-6] = '\0';
				strcpy(ip, buffer);
			break;
			case 1:
				memcpy(buffer, line+5, cread-6);
				buffer[cread-6] = '\0';
				(*port) = atoi(buffer);
			break;
		}
		++i;
	}
}

int main() {
	int port;
	char ip[15];
	int clientSocket;
	char buffer[1024], conv[10];
	float n = 0.9887777;
	srand(time(NULL));

	readS_info(ip, &port);
	clientSocket = inicializa_e_conecta(port, ip);

	while(1) {
		sleep(2);
	        strcpy(buffer, "cli_01: ");
		snprintf(conv, 10, "%f", n);
	       	strcat(buffer, conv);
	        send(clientSocket,buffer,strlen(buffer)+1,0);
		printf("Data sent: %s\n", buffer);
		n -= 0.005;
	}
	
	return 0;
}
