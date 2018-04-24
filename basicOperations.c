#include "basicOperations.h";
typedef struct Multiplicao {
    int A:4;
    int Q:4;
    unsigned int Q_1:1;
    int M:4;
} multiplicacao;

int complementar(int x) { return (~x) + 1; }

int soma(int x, int y) {
    int result, acum;
    result = x ^ y;
    acum = x & y;
    while (acum != 0) {
        acum = __leftShift(acum);
        x = result;
        y = acum;
        result = x ^ y;
        acum = x & y;
    }
    return result;
}

int subtracao(int x, int y) { return soma(x, complementar(y)); }

void produto(int x, int y) {
    multiplicacao m;
    int count = 4;
    m.A = 0;
    m.Q_1 = 0;
    m.Q = x;
    m.M = y;
}

void divisao(int x, int y) {
    //TODO
}

void int2bin(int n){
    static char bin[4];
    int original = n;
    int x;

    for(x=0; x<4; x++)
    {
        bin[x] = n & 0x8 ? '1' : '0';
        n = __leftShift(n);
    }
    printf("%s", bin);
}

//PRIVATE FUNCTIONS
int __extractLastBit(int x) { return x & 1; }
int __extractFirstBit(int x) { return x & 8; }
int __rightShift(int x) { return x >> 1; }
int __leftShift(int x) { return x << 1; }

