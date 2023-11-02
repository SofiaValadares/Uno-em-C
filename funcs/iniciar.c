#include <stdio.h>
#include <stdlib.h>

#include "iniciar.h"
#include "structs.h"
#include "baralho.h"
#include "cartas.h"
#include "jogador.h"

void criarArqSentido() {
    FILE *f;

    f = fopen(ARQUIVO_SENTIDO, "w+");

    if (f == NULL) {
        printf("Erro: ao criar arquivo %s.....\n", ARQUIVO_SENTIDO);
        exit(0);
    }

    fprintf(f, "1");

    fclose(f);
}

void iniciar(Baralho **deck) {
    criarArqSentido();

    *deck = criarDeck(ARQUIVO_BARALHO);
    
    // criar jogadores aqui eba

    primeiraCarta(deck);
}


int lerSentido() {
    FILE *f;

    f = fopen(ARQUIVO_SENTIDO, "r");

    if (f == NULL) {
        printf("Erro: ao abrir arquivo %s.....\n", ARQUIVO_SENTIDO);
        exit(1);
    }

    int sent;
    fscanf(f, "%d", &sent);

    fclose(f);

    return sent;
}


// Testes eba
void imprimirCartas(Baralho *deck) {
    while (deck != NULL){
        printf("%s\n", nomeCarta(deck));
        deck = deck->prox;
    }
    
}