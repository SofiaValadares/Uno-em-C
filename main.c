#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "baralho.h"
#include "cartas.h"
#include "jogador.h"
#include "iniciar.h"

int main(void){
    Baralho *deck = NULL;
    Jogador *players = NULL;
    
    iniciar(&deck, &players);
    return 0;
}