#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jogador.h"
#include "baralho.h"
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

   for(int i = 0; i<quantJogadores; i++){
        if(head == NULL){
            head = criarJogador(deck);
        }
   }



}

void jogadorTurno(Jogador **player, Baralho **deck) {
    if (verifcarMao((*player)->mao, *deck)) {
        textoBold("Digite o numero da posicao da carta que deseja jogar: ");

        int nun;
        scanf("%d", &nun);

        Baralho *card = buscarCartaMao((*player)->mao, nun);

        if (veficarCarta(card, *deck)) {
            cartasEspeciais(&card);

            addBaralho(deck, card->tipo, card->simbulo);
            removerMao(player, card);
        } else {
            printf("Carta invalida\n");
            jogadorTurno(player, deck);
        }
    } else {
        addMao(player, deck);
        textoBold("Infelizmente você não tem cartas que possam ser jogadas :(\n");
        textoBold("Então você automaticamente compra uma carta!!\n\n");

        textoBold("Carta comprada: ");
        printf("%s\n", nomeCarta((*player)->mao));

        limparBuff();
        textoBold("Digite enter antes de passar para o proximo jogador....");
        while (getchar() != '\n');
    }
}

void passarTurno(Jogador **player) {
    if (lerSentido()) {
        *player = (*player)->prox;
    } else {
        *player = (*player)->ant;
    }
}