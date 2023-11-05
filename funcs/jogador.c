#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jogador.h"
#include "baralho.h"
#include "cartas.h"
#include "iniciar.h"
#include "structs.h"
#include "ui.h"

Jogador* criarJogador(Baralho **head){
    Jogador *novoJogador = (Jogador*)malloc(sizeof(Jogador));

    char nomeJogador[51];
    textoBold("Digite seu nome: ");
    scanf("%s", nomeJogador);

    strcpy(novoJogador->nome, nomeJogador);
    novoJogador->qnt = 7;
    novoJogador->mao = criarMao(head);
    return novoJogador;
   
}

Jogador* listaJogadores(Baralho **deck){
    Jogador *head = NULL;
    Jogador *tail = NULL;

    int quantJogadores;
    textoBold("Digite a quantidade de jogadores (mínimo de 2 e máximo de 10 jogadores): ");
    scanf("%d", &quantJogadores);

    while (quantJogadores < 2 || quantJogadores > 10) {
        printf(RED "Quantidade invalida!!! Digite uma quantidade ente 2 e 10: " RESET);
        scanf("%d", &quantJogadores);
    }

    for (int i = 0; i < quantJogadores; i++) {
        Jogador *novo = criarJogador(deck);
        if (head == NULL) {
            head = novo;
            tail = novo;
        } else {
            tail->prox = novo;
            novo->ant = tail;
            tail = novo;
        }
    }

    head->ant = tail;
    tail->prox = head;

    return head;
}

void jogadorTurno(Jogador **player, Baralho **deck) {
    if (verifcarMao((*player)->mao, *deck)) {
        textoBold("Digite o numero da posicao da carta que deseja jogar: ");

        int nun;
        scanf("%d", &nun);

        while (nun < 1 || nun > (*player)->qnt) {
            printf(RED "Numero invalido!!! Digite um dos numeros cizas a esquerda: " RESET);
            scanf("%d", &nun);
        }

        Baralho *card = buscarCartaMao((*player)->mao, nun);

        if (veficarCarta(card, *deck)) {
            addBaralho(deck, card->tipo, card->simbulo);
            removerMao(player, card);

            cartasEspeciais(player, deck);
        } else {
            printf("Carta invalida\n");
            jogadorTurno(player, deck);
        }

    } else {
        addMao(player, deck);
        textoBold("Infelizmente você não tem cartas que possam ser jogadas :(\n");
        textoBold("Então você automaticamente compra uma carta!!\n\n");

        textoBold("Carta comprada: ");
        printf("%s\n\n", nomeCarta((*player)->mao));

        //limparBuff();
        textoBold("Digite enter antes de passar para o proximo jogador....");
        limparBuff();
        printf("\n");
    }
}

void passarTurno(Jogador **player) {
    if (lerSentido()) {
        *player = (*player)->prox;
    } else {
        *player = (*player)->ant;
    }
}

void voltarTurno(Jogador **player) {
    if (!lerSentido()) {
        *player = (*player)->prox;
    } else {
        *player = (*player)->ant;
    }
}