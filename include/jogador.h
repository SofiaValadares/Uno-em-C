#ifndef __JOGADOR_LIB__
#define __JOGADOR_LIB__

#include "structs.h"

Jogador* criarJogador(Baralho **head);
Jogador* listaJogadores(Baralho **deck);
void jogadorTurno(Jogador **player, Baralho **deck);
void passarTurno(Jogador **player);
void voltarTurno(Jogador **player);

#endif //__JOGADOR_LIB__