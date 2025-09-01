#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main() {
    // usamos uint32_t para asegurarnos que estemos usando un int que tenga suficiente rango para contar hasta 6 millones
    uint32_t resultados[6] = {0};

    // generamos el numero inicial de la secuencia "aleatoria" a partir de un valor del sistema
    srand(time(NULL));
    // vamos a a sumar 1 al numero que corresponda entre 0 y 5 (la pos i corresponde al nro i+1)
    // lo hacemos 6 * 10^6 veces
    for (size_t i = 0; i < 6e6; i++) {
        resultados[rand() % 6]++;
    }
    for (int i = 0; i < 6; i++) {
        printf("%i: %u\n", i+1, resultados[i]);
    }
    return 0;
}

