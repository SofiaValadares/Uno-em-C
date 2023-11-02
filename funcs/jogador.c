#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jogador.h"
#include "baralho.h"
#include "structs.h"

Jogador* criarJogador(Baralho **head){
    Jogador *novoJogador = (Jogador*)malloc(sizeof(Jogador));

    char nomeJogador[51];
    printf("Digite seu nome: ");
    scanf("%s", &nomeJogador);

    strcpy(novoJogador->nome, nomeJogador);
    novoJogador->qnt = 7;
    novoJogador->mao = criarMao(head);
    return novoJogador;
   
}

Jogador* listaJogadores(Baralho **deck){
   Jogador *head = NULL;
   Jogador *tail = NULL;

   int quantJogadores;
   printf("Digite a quantidade de jogadores (mínimo de 2 e máximo de 10 jogadores): ");
   scanf("%d", &quantJogadores);

   for(int i = 0; i<quantJogadores; i++){
        if(head == NULL){
            head = criarJogador(deck);
        }
   }



}