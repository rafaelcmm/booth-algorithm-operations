#include <stdio.h>
#include <stdlib.h>
#include "basicOperations.h"
int main()
{
    int x = -2;
    int y = -2;

    multiplicacao m;
    m.A = 0;
    m.Q_1 = 0;
    m.Q = x;
    m.M = y;
    m.counter = 4;

    printf("Soma: %d\n", soma(x, y));
    printf("Subtracao: %d\n", subtracao(x, y));
    printf("Procedimento do Produto: \n");
    produto(m);
}
