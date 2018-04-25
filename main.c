#include <stdio.h>
#include <stdlib.h>
#include "basicOperations.h"
void preencheValores(int* x, int* y) {
    printf("Digite um valor para X: ");
    scanf("%d", x);
    printf("Digite um valor para Y: ");
    scanf("%d", y);
}

void printResultados(int x, int y, multiplicacao m) {
    printf("\n\n");
    printf("Soma: %d\n", soma(x, y));
    printf("Subtracao: %d\n", subtracao(x, y));
    printf("Procedimento do Produto de %d x %d: \n", x, y);
    produto(m);
}

int main()
{
    int x, y;

    preencheValores(&x, &y);

    multiplicacao m;
    m.A = 0;
    m.Q_1 = 0;
    m.Q = x;
    m.M = y;
    m.counter = 4;

    printResultados(x, y, m);
}
