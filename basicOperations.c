#include "basicOperations.h";

int complementar(int x) { return (~x) + 1; }

int soma(int x, int y) {
    int sum, carry;
    sum = x ^ y;
    carry = x & y;
    while (carry != 0) {
        carry = carry << 1;
        x = sum;
        y = carry;
        sum = x ^ y;
        carry = x & y;
    }
    return sum;
}

int subtracao(int x, int y) {
    return soma(x, complementar(y));
}
