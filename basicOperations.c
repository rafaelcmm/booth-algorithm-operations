#include "basicOperations.h";
int complementar(int x) { return (~x) + 1; }

int soma(int x, int y) {
    int sum, carry;
    sum = x ^ y;
    carry = x & y;
    while (carry != 0) {
        carry = __leftShift(carry);
        x = sum;
        y = carry;
        sum = x ^ y;
        carry = x & y;
    }
    return sum;
}

int subtracao(int x, int y) { return soma(x, complementar(y)); }

void produto(int x, int y) {
    //TODO
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
int __rightShift(int x) { return x >> 1; }
int __leftShift(int x) { return x << 1; }

