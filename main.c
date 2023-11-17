#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "baralho.h"
#include "cartas.h"
#include "jogador.h"
#include "iniciar.h"
#include "ui.h"

int main(void){
    Baralho *deck = NULL;
    Jogador *players = NULL;
    
    iniciar(&deck, &players);

    while (1) {
        turnoInterface(players, deck);
        jogadorTurno(&players, &deck);

        if (players->mao == NULL) {
            break;
        }

        passarTurno(&players);
    }

    podio(&players);
    interfaceFim(players);

    return 0;
}