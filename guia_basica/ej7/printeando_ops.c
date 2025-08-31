#include <stdio.h>


int main() {
    int a = 5;
    int b = 3;
    int c = 2;
    int d = 1;

    printf("a = %i \n", a);
    printf("a = %04x \n", a);
    printf("b = %i \n", b);
    printf("b = %04x \n", b);
    printf("c = %i \n", c);
    printf("c = %04x \n", c);
    printf("d = %i \n", d);
    printf("d = %04x \n", d);

    printf("a + b * c / d = %i \n", a + b * c / d);

    printf("a %% b = %i \n", a % b);

    printf("a == b = %i \n", a == b);

    printf("a != b = %i \n", a != b);

    printf("a & b = %04x \n", a & b);
    printf("a | b = %04x \n", a | b);
    printf("~a = %04x \n", ~a);
    printf("a && b = %i \n", a && b);
    printf("a || b = %i \n", a || b);
    printf("a << 1 = %04x \n", a << 1);
    printf("a >> 1 = %04x \n", a >> 1);
    printf("a += b = %i \n", a += b);
    printf("a -= b = %i \n", a -= b);
    printf("a *= b = %i \n", a *= b);
    printf("a /= b = %i \n", a /= b);
    printf("a %%= b = %i \n", a %= b);

    return 0;
}