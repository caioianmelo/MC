#include "cliente.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int clientSocket = inicializa_e_conecta(7891);
  char buffer[1024];
  int i;
  srand(time(NULL));

  while (1)
  {
      usleep(2000000);
      i = rand()%100;
      sprintf(buffer,"%d\n", i);
      send(clientSocket,buffer,strlen(buffer)+1,0);
      printf("Data sent: %s\n", buffer);
  }

  return 0;
}
