#include <stdio.h>

typedef struct {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;

monstruo_t evolution(monstruo_t m) {
    m.ataque+= 10;
    m.defensa += 10;

    return m;
}

int main(void) {

    monstruo_t m = {"a", 1, 2, 3};

    printf("*Monstruo antes de evolucionar %s: %ihp, %fattk, %fdef\n", m.nombre, m.vida, m.ataque, m.defensa);

    monstruo_t m2 = evolution(m);

    printf("*Monstruo después de evolucionar %s: %ihp, %fattk, %fdef\n", m2.nombre, m2.vida, m2.ataque, m2.defensa);

    return 0;
}