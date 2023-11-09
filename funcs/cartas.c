#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cartas.h"
#include "baralho.h"
#include "structs.h"
#include "iniciar.h"
#include "jogador.h"
#include "ui.h"

char* nomeCarta(Baralho *card) {
    char *strCard = (char*)malloc(31 * sizeof(char));

    if (card->tipo == 0) {
        if (card->simbulo == 1) {
            return "Coringa";
        } else if (card->simbulo == 2) {
            return "Coringa +4";
        }
    }

    switch(card->simbulo) { // Codigo do Simbulo aqui
        case 0:
            strcpy(strCard, "0 ");
            break;
        case 1:
            strcpy(strCard, "1 ");
            break;
        case 2:
            strcpy(strCard, "2 ");
            break;
        case 3:
            strcpy(strCard, "3 ");
            break;
        case 4:
            strcpy(strCard, "4 ");
            break;
        case 5:
            strcpy(strCard, "5 ");
            break;
        case 6:
            strcpy(strCard, "6 ");
            break;
        case 7:
            strcpy(strCard, "7 ");
            break;
        case 8:
            strcpy(strCard, "8 ");
            break;
        case 9:
            strcpy(strCard, "9 ");
            break;
        case 10:
            strcpy(strCard, "Inverter ");
            break;
        case 11:
            strcpy(strCard, "Bloquear ");
            break;
        case 12:
            strcpy(strCard, "+2 ");
            break;
        case 13:
            strcpy(strCard, "Coringa ");
            break;
        case 14:
            strcpy(strCard, "Coringa +4 ");
            break;
    }

    switch(card->tipo) { // As cores aqui
        case 1:
            strcat(strCard, GREEN "Verde" RESET);
            break;
        case 2:
            strcat(strCard, BLUE "Azul" RESET);
            break;
        case 3:
            strcat(strCard, YELLOW "Amarelo" RESET);
            break;
        case 4:
            strcat(strCard, RED "Vermelho" RESET);
            break;
    }

    return strCard;
}

int veficarCarta(Baralho *card, Baralho *deck) {
    return card->tipo == 0 || card->tipo == deck->tipo || card->simbulo == deck ->simbulo;
}

int verifcarMao(Baralho *mao, Baralho *deck) {
    while (mao != NULL) {
        if (veficarCarta(mao, deck)) {
            return 1;
        }
        mao = mao->prox;
    }

    return 0;
}

void inverter() {
    int sent = lerSentido();

    FILE *f;

    f = fopen(ARQUIVO_SENTIDO, "w+");

    if (f == NULL) {
        printf("\033[31mErro: ao abrir arquivo %s.....\n\033[0m", ARQUIVO_SENTIDO);
        exit(1);
    }

    if (sent) {
        fprintf(f, "0");
    } else {
        fprintf(f, "1");
    }

    fclose(f);
}

void bloquear(Jogador **player, Baralho *deck) {
    passarTurno(player);

    turnoInterface(*player, deck);
    textoBold("Voce foi bloqueado. Digite enter antes de passar para o proximo player.....");
    limparBuff();
    getchar();
}

void comprar2(Jogador **player, Baralho **deck) {
    passarTurno(player);

    turnoInterface(*player, *deck);

    (*player)->qnt = countBaralho((*player)->mao);

    textoBold("Voce comprou mais 2 cartas.\n");

    for (int i = 0; i < 4; i ++) {
        addMao(player, deck);
        printf("%s\n", nomeCarta((*player)->mao));
    }

    textoBold("Digite enter para continuar.....");
    limparBuff();

    voltarTurno(player);
}

void coringa(Baralho **deck) {
    printf("1 - " GREEN "Verde" RESET "\n");
    printf("2 - " BLUE "Azul" RESET "\n");
    printf("3 - " YELLOW "Amarelo" RESET "\n");
    printf("4 - " RED "Vermelho" RESET "\n");

    textoBold("Escolha uma cor: ");

    int nun;
    scanf("%d", &nun);

    (*deck)->tipo = nun;
    (*deck)->simbulo = 13;
}

void coringa4(Jogador **player, Baralho **deck) {
    printf("1 - " GREEN "Verde" RESET "\n");
    printf("2 - " BLUE "Azul" RESET "\n");
    printf("3 - " YELLOW "Amarelo" RESET "\n");
    printf("4 - " RED "Vermelho" RESET "\n");

    textoBold("Escolha uma cor: ");

    int nun;
    scanf("%d", &nun);

    (*deck)->tipo = nun;
    (*deck)->simbulo = 14;

    passarTurno(player);

    turnoInterface(*player, *deck); 

    
    (*player)->qnt = countBaralho((*player)->mao);


    textoBold("Voce comprou mais 4 cartas.\n");

    for (int i = 0; i < 4; i ++) {
        addMao(player, deck);
        printf("%s\n", nomeCarta((*player)->mao));
    }

    textoBold("Digite enter para continuar.....");
    limparBuff();

    voltarTurno(player);
}

void cartasEspeciais(Jogador **player, Baralho **deck) {
    if ((*deck)->simbulo == 10) {
        inverter();
    } else if ((*deck)->simbulo == 11) {
        bloquear(player, *deck);
    } else if ((*deck)->simbulo == 12) {
        comprar2(player, deck);
    }

    if ((*deck)->tipo == 0) {
        if((*deck)->simbulo == 1) {
            coringa(deck);
        } else if ((*deck)->simbulo == 2) {
            coringa4(player, deck);
        }
    }
}