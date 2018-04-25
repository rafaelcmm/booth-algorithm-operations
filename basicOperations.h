#ifndef BASICOPERATIONS_H_INCLUDED
#define BASICOPERATIONS_H_INCLUDED

typedef struct Multiplicao {
    int A:4;
    int Q:4;
    unsigned int Q_1:1;
    int M:4;
    int counter;
} multiplicacao;

int soma(int x, int y);
int subtracao(int x, int y);
void produto(multiplicacao m);
void divisao(int x, int y);

int complementar(int x);

void int2bin(int n);

#endif // BASICOPERATIONS_H_INCLUDED
