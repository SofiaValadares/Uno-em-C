#include <stdio.h>
#include <stdlib.h>

#include "iniciar.h"
#include "structs.h"
#include "baralho.h"
#include "cartas.h"
#include "jogador.h"
#include "ui.h"

void criarArqSentido() {
    FILE *f;

    f = fopen(ARQUIVO_SENTIDO, "w+");

    if (f == NULL) {
        printf("033[31mErro: ao criar arquivo %s.....\n\033[0m", ARQUIVO_SENTIDO);
        exit(0);
    }

    fprintf(f, "1");

    fclose(f);
}

void iniciar(Baralho **deck, Jogador **players) {
    textoUno();
    criarArqSentido();

    *deck = criarDeck(ARQUIVO_BARALHO);
    *players = listaJogadores(deck);
    
    primeiraCarta(deck);
}


int lerSentido() {
    FILE *f;

    f = fopen(ARQUIVO_SENTIDO, "r");

    if (f == NULL) {
        printf("033[31mErro: ao abrir arquivo %s.....\n\033[0m", ARQUIVO_SENTIDO);
        exit(1);
    }

    int sent;
    fscanf(f, "%d", &sent);

    fclose(f);

    return sent;
}



