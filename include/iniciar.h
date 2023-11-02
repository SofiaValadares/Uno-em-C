#ifndef __INICIO_LIB__
#define __INICIO_LIB__

#include "structs.h"

void criarArqSentido();
void iniciar(Baralho **deck, Jogador **players) ;
int lerSentido();



void imprimirCartas(Baralho *deck);
void imprimirPlayers(Jogador *head);
#endif //__INICIO__LIB__