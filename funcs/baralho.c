#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "baralho.h"
#include "structs.h"

Baralho* criarDeck(char* nome_arquivo) {
    Baralho* deck = NULL;
    FILE *f;

    f = fopen(nome_arquivo, "r");

    if (f == 0) {
        printf("Erro: ao tentar abrir arquivo %s para leitura.....\n", nome_arquivo);
        exit(1);
    }

    int tipo;
    int simbulo;

    while(fscanf(f, "%d %d\n", &tipo, &simbulo) != EOF) {
        addBaralho(&deck, tipo, simbulo);
        tipo = 0;
        simbulo = 0;
    } 

    fclose(f);

    if (deck == NULL) {
        printf("Erro: ao ler o baralho.....\n");
        exit(1);
    }   

    return deck;
}

void addBaralho(Baralho **head, int tipo, int simbulo) {
    Baralho *novaCarta = (Baralho*)malloc(sizeof(Baralho));
    novaCarta->tipo = tipo;
    novaCarta->simbulo = simbulo;
    novaCarta->prox = NULL;

    if (*head == NULL) {
        *head = novaCarta;
    } else {
        novaCarta->prox = *head;
        *head = novaCarta;
    }
}

Baralho* comprarCarta(Baralho **head) {
    Baralho *n = (*head)->prox;

    srand(time(0)); // mover para a main
    int nunCard = rand() % countBaralho(n);

    Baralho *anterior = NULL;    

    for (int i = 0; i < nunCard; i++) {
        anterior = n;
        n = n->prox;
    }

    if (n == NULL) {
        printf("Erro: ao comprar carta.....\n");
        exit(1);
    }

    if (n->prox == NULL) {
        anterior->prox = NULL;
    } else if (anterior == NULL) {
        (*head)->prox = n->prox;
    } else {
        anterior->prox = n->prox;
    }

    return n;
}

int countBaralho(Baralho *head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->prox;
    }

    return count;
}