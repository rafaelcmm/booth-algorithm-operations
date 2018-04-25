#include "basicOperations.h";
//PRIVATE FUNCTIONS
multiplicacao __justRightShift(multiplicacao m) {
    int lastABit = __extractLastBit(m.A);
    int firstQBit = __extractFirstBit(m.Q);
    int lastQBit = __extractLastBit(m.Q);
    m.A = __rightShift(m.A);
    m.Q = __rightShift(m.Q);
    if (lastABit == 1 && firstQBit == 0)
        m.Q = m.Q + 8;
    if (lastABit == 0 && firstQBit == 1)
        m.Q = m.Q - 8;
    m.Q_1 = lastQBit;

    return m;
}
multiplicacao __subtractAndRightShift(multiplicacao m) {
    m.A = subtracao(m.A, m.M);
    m = __justRightShift(m);

    return m;
}
multiplicacao __sumAndRightShift(multiplicacao m) {
    m.A = soma(m.A, m.M);
    m = __justRightShift(m);

    return m;
}
int __printBoothStep(multiplicacao m) {
    int2bin(m.A);
    printf("    ");
    int2bin(m.Q);
    printf("    ");
    printf("%d", m.Q_1);
    printf("    ");
    int2bin(m.M);
    printf("    Steps Remaining: ");
    printf("%d\n", m.counter);
}
int __extractLastBit(int x) { return x & 1; }
int __extractFirstBit(int x) { return x & 8 ? 1 : 0; }
int __rightShift(int x) { return x >> 1; }
int __leftShift(int x) { return x << 1; }

//END PRIVATE FUNCTIONS

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

void produto(multiplicacao m) {
    if (m.counter == 4) {
        printf("--------- ESTADO INICIAL ----------\n");
        __printBoothStep(m);
        printf("-----------------------------------\n");
    }

    if (m.counter > 0) {
        if (__extractLastBit(m.Q) == 1 && m.Q_1 == 0) {
            m = __subtractAndRightShift(m);
            m.counter--;
            __printBoothStep(m);
            produto(m);
        } else if (__extractLastBit(m.Q) == 0 && m.Q_1 == 1) {
            m = __sumAndRightShift(m);
            m.counter--;
            __printBoothStep(m);
            produto(m);
        } else {
            m = __justRightShift(m);
            m.counter--;
            __printBoothStep(m);
            produto(m);
        }
    } else {
        printf("\n");
        printf("Resultado Final: ");
        int2bin(m.A);
        int2bin(m.Q);
        printf("\n");
    }
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

