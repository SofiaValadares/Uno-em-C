#ifndef __CARTAS_LIB__
#define __CARTAS_LIB__

#include "structs.h"

char* nomeCarta(Baralho *card);
int veficarCarta(Baralho *card, Baralho *deck);
int verifcarMao(Baralho *mao, Baralho *deck);
void inverter();
void bloquear(Jogador **player, Baralho *deck);
void comprar2(Jogador **player, Baralho **deck);
void coringa(Baralho **deck);
void coringa4(Jogador **player, Baralho **deck);
void cartasEspeciais(Jogador **player, Baralho **deck);

#endif //__CARTAS__LIB__