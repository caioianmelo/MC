#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int inicializa_e_conecta(uint16_t porta, char * restrict ip);

#endif // CLIENTE_H_INCLUDED
