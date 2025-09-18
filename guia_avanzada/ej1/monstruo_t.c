#include <stdio.h>

#define N 2

struct monstruo_t {
    char* nombre;
    int vida;
    double ataque;
    double defensa;
};

int main(void) {

    struct monstruo_t monstruos[] = {{"a", 1, 2, 3},{"b", 1, 2, 3}};

    for (size_t i = 0; i < N; i++) {
        printf("*Monstruo %s: %ihp\n", monstruos[i].nombre, monstruos[i].vida);
    }

    return 0;
}