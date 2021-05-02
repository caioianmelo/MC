#include "cliente.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int clientSocket = inicializa_e_conecta(7891);
  char buffer[1024], conv[10];
  float n = 0.9887777;
  srand(time(NULL));

  while(1)
  {
      usleep(2000000);
      strcpy(buffer, "cli_1: ");
	gcvt(n, 7, conv);
	strcat(buffer, conv);
      send(clientSocket,buffer,strlen(buffer)+1,0);
      printf("Data sent: %s\n", buffer);
      n -= 0.005;
  }

  return 0;
}
