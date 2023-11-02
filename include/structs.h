#ifndef __STRUCTS_LIB__
#define __STRUCTS_LIB__

typedef struct baralho{
    int carta;
    struct baralho *prox;
} Baralho;


typedef struct jogador{
    char nome[51];
    Baralho *mao;
    struct usuarios *prox;
    struct usuarios *ant;
} Jogador;


#endif //__STRUCTS_LIB__