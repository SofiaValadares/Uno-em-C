#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cartas.h"
#include "structs.h"
#include "ui.h"

void textoUno() {
    limparTerminal();
    printf(HIDDEN BG_RED "    UNO         " BG_YELLOW "    UNO         " BG_GREEN "    UNO         " BG_BLUE "     UNO" RESET BG_BLUE BOLD "U N O" HIDDEN "UNO      " BG_GREEN "    UNO         " BG_YELLOW "    UNO         " BG_RED "    UNO         " RESET "\n\n");
   
    centralizarTexto(ITALIC UNDERLINE "Onde amizades são testadas e cartas são arremessadas!" RESET);
    printf("\n\n\n\n");
}

void textoBold(const char *texto) {
    printf(BOLD);
    printf("%s", texto);
    printf(RESET);
}

void centralizarTexto(const char *texto) {
    // Obtenha a largura da janela do terminal

    int terminal_width = 135; // Defina um valor padrão  se não for possível obter a largura real

    if (strlen(texto) > terminal_width) {
        imprimirComQuebrasDeLinha(texto);
        return;
    }

    // Calcula o número de espaços à esquerda para centralizar o texto
    int espacos_esquerda = (terminal_width - strlen(texto)) / 2;

    // Imprime os espaços à esquerda seguidos pelo texto
    for (int i = 0; i < espacos_esquerda; i++) {
        printf(" ");
    }

    printf("%s\n", texto);
}

void imprimirComQuebrasDeLinha(const char *texto) {
    int comprimento = strlen(texto);

    for (int i = 0; i < comprimento; i++) {
        // Imprime o caractere atual
        printf("%c", texto[i]);

        // Insere uma quebra de linha a cada 150 caracteres
        if ((i + 1) % 77 == 0) {
            printf("\n");
        }
    }

    printf("\n"); // Certifica-se de haver uma quebra de linha no final do texto
}

void limparTerminal() {
    #ifdef _WIN32
        // Sistema Windows
        system("cls");
    #else
        // Sistema macOS ou Linux
        system("clear");
    #endif
}