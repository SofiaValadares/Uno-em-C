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
        printf("\033[31mErro: ao tentar abrir arquivo %s para leitura.....\n\033[0m", nome_arquivo);
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
        printf("\033[31mErro: ao ler o baralho.....\n\033[0m");
        exit(1);
    }   

    return deck;
}

void addBaralho(Baralho **head, int tipo, int simbulo) {
    Baralho *novaCarta = (Baralho*)malloc(sizeof(Baralho));

    if (novaCarta == NULL) {
        printf("\033[31mErro: ao alocar memória para nova carta.....\n\033[0m");
        exit(1);
    }

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
    if (head == NULL) {
        printf("\033[31mErro: tentativa de comprar carta de baralho vazio.....\n\033[0m");
        exit(1);
    }

    Baralho *n = (*head)->prox;
    Baralho *card = (Baralho*)malloc(sizeof(Baralho));

    if (card == NULL) {
        printf("\033[31mErro: ao alocar memória para nova carta.....\n\033[0m");
        exit(1);
    }

    srand(time(0)); // mover para a main
    int nunCard = rand() % countBaralho(n);

    Baralho *anterior = NULL;    

    for (int i = 0; i < nunCard; i++) {
        anterior = n;
        n = n->prox;
    }

    if (n == NULL) {
        printf("\033[31mErro: tentativa de comprar carta fora dos limites do baralho.....\n\033[0m");
        exit(1);
    }

    card->tipo = n->tipo;
    card->simbulo = n->simbulo;
    card->prox = NULL;

    if (n->prox == NULL) {
        anterior->prox = NULL;
        free(n);
    } else if (anterior == NULL) {
        (*head)->prox = n->prox;
        free(n);
    } else {
        anterior->prox = n->prox;
        free(n);
    }

    return card;
}

int countBaralho(Baralho *head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->prox;
    }

    return count;
}

Baralho* criarMao(Baralho** head) {
    Baralho *mao = NULL;

    for (int i = 0; i < 7; i++) {
        Baralho *novaCarta = comprarCarta(head);

        if (novaCarta == NULL) {
            printf("\033[31mErro: ao comprar carta.....\n\033[0m");
            exit(1);
        }

        if (mao == NULL) {
            mao = novaCarta;

        } else {
            novaCarta->prox = mao;
            mao = novaCarta;
        }
    }

    return mao;
}

void primeiraCarta(Baralho **head) {
    Baralho *primeiroCard = comprarCarta(head);

    if (primeiroCard == NULL) {
        printf("\033[31mErro: ao comprar carta.....\n\033[0m");
        exit(1);
    }

    primeiroCard->prox = *head;
    *head = primeiroCard;
}

void addMao(Jogador **player, Baralho **deck) {
    if (*player == NULL) {
        printf("\033[31mErro: ao acessar o jogador.....\n\033[0m");
        exit(1);
    }

    (*player)->qnt++;

    Baralho *novoCard = comprarCarta(deck);

    if (novoCard == NULL) {
        printf("\033[31mErro: ao comprar carta.....\n\033[0m");
        exit(1);
    }

    novoCard->prox = (*player)->mao;
    (*player)->mao = novoCard;
}