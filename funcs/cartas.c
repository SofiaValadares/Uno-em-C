#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cartas.h"
#include "structs.h"
#include "iniciar.h"
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

void inverter() {
    int sent = lerSentido();

    FILE *f;

    f = fopen(ARQUIVO_SENTIDO, "w+");

    if (f == NULL) {
        printf("Erro: ao abrir arquivo %s.....\n", ARQUIVO_SENTIDO);
        exit(1);
    }

    if (sent) {
        fprintf(f, "0");
    } else {
        fprintf(f, "1");
    }

    fclose(f);
}