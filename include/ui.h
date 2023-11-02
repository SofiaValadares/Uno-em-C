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
#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[1;33m"
#define BLUE       "\033[1;34m"
#define MAGENTA    "\033[1;35m"
#define CYAN       "\033[1;36m"
#define WHITE      "\033[1;97m" 

// Cores de fundo
#define BG_RED        "\033[41;37m"
#define BG_GREEN      "\033[42;37m"
#define BG_YELLOW     "\033[43;37m"
#define BG_BLUE       "\033[44;37m"
#define BG_MAGENTA    "\033[45;37m"
#define BG_CYAN       "\033[46;37m"


void textoUno();
void centralizarTexto(const char *texto);
void imprimirComQuebrasDeLinha(const char *texto);
void limparTerminal();

#endif //__UI_LIB__