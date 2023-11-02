#ifndef __STRUCTS_LIB__
#define __STRUCTS_LIB__

#define ARQUIVO_BARALHO "arq/baralhoUno.txt"
#define ARQUIVO_SENTIDO "bin/sentido.txt"

typedef struct baralho{
    int tipo; 
    int simbulo; 
    struct baralho *prox;
} Baralho;


typedef struct jogador{
    char nome[51];
    int qnt; 
    Baralho *mao;
    struct usuarios *prox;
    struct usuarios *ant;
} Jogador;


#endif //__STRUCTS_LIB__