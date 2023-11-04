#ifndef __BARALHO_LIB__
#define __BARALHO_LIB__

#include "structs.h"

Baralho* criarDeck(char* nome_arquivo);
void addBaralho(Baralho **pilha, int tipo, int simbulo);
Baralho* comprarCarta(Baralho **head);
int countBaralho(Baralho *head);
Baralho* criarMao(Baralho** head);
void primeiraCarta(Baralho **head);
void addMao(Jogador **player, Baralho **deck);
Baralho *buscarCartaMao(Baralho *mao, int nun);
void removerMao(Jogador **player, Baralho *card);

#endif //__BARALHO_LIB__