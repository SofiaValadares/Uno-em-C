#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cartas.h"
#include "structs.h"

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
            strcpy(strCard, "X");
            break;
        case 1:
            strcpy(strCard, "X");
            break;
        case 2:
            strcpy(strCard, "X");
            break;
        case 3:
            strcpy(strCard, "X");
            break;
        case 4:
            strcpy(strCard, "X");
            break;
        case 5:
            strcpy(strCard, "X");
            break;
        case 6:
            strcpy(strCard, "X");
            break;
        case 7:
            strcpy(strCard, "X");
            break;
        case 8:
            strcpy(strCard, "X");
            break;
        case 9:
            strcpy(strCard, "X");
            break;
        case 10:
            strcpy(strCard, "X");
            break;
        case 11:
            strcpy(strCard, "X");
            break;
        case 12:
            strcpy(strCard, "X");
            break;
    }

    switch(card->tipo) { // As cores aqui
        case 1:
            strcat(strCard, "XXX");
            break;
        case 2:
            strcat(strCard, "XXX");
            break;
        case 3:
            strcat(strCard, "XXX");
            break;
        case 4:
            strcat(strCard, "XXX");
            break;
    }
}