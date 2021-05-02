#ifndef SERVIDOR_H_INCLUDED
#define SERVIDOR_H_INCLUDED

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int inicializa_e_espera(uint16_t porta);

#endif // SERVIDOR_H_INCLUDED
