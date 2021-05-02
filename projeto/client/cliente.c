#include "cliente.h"

int inicializa_e_conecta(uint16_t porta, char * restrict ip) {
	int clientSocket;
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(porta);
	serverAddr.sin_addr.s_addr = inet_addr(ip);
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
	
	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
	
	return clientSocket;
}
