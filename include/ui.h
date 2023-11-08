#ifndef __UI_LIB__
#define __UI_LIB__

#define RESET      "\033[0m"
#define BOLD       "\033[1m"
#define UNDERLINE  "\033[4m"
#define ITALIC     "\033[3m"
#define STRIKETHROUGH "\033[9m"
#define INVERT     "\033[7m"
#define HIDDEN     "\033[8m"

// Cores do texto
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"
#define CYAN       "\033[36m"
#define GRAY       "\033[90m"
#define PURPLE     "\033[35m"
#define WHITE      "\033[97m" 

// Cores de fundo
#define BG_RED        "\033[41;37m"
#define BG_GREEN      "\033[42;37m"
#define BG_YELLOW     "\033[43;37m"
#define BG_BLUE       "\033[44;37m"
#define BG_MAGENTA    "\033[45;37m"
#define BG_CYAN       "\033[46;37m"

#include "structs.h" 

void textoUno();
void centralizarTexto(const char *texto);
void listaJogadoresImprimir(Jogador *head);
void imprimirCartas(Baralho *deck);
void turnoInterface(Jogador *player, Baralho *deck);
void interfaceFim(Jogador *player);
void textoBold(const char *texto);
void imprimirComQuebrasDeLinha(const char *texto);
void limparTerminal();
void limparBuff();

#endif //__UI_LIB__