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

    //turnoInterface(players, deck);
    return 0;
}