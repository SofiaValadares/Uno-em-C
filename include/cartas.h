#ifndef __CARTAS_LIB__
#define __CARTAS_LIB__

#include "structs.h"

char* nomeCarta(Baralho *card);
int veficarCarta(Baralho *card, Baralho *deck);
int verifcarMao(Baralho *mao, Baralho *deck);
void inverter();
void coringa(Baralho **deck);
void coringa4(Baralho **deck);
void cartasEspeciais(Baralho **card);

#endif //__CARTAS__LIB__