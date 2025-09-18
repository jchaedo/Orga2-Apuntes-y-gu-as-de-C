#include <stdio.h>
#include <stdint.h>

int main(){
    int8_t memoria[] = {-1, 31, 42, 0, 55, 67, -128, 127, -99};
    uint8_t *x = (uint8_t*) &memoria[2];
    int8_t *y = &memoria[0];

    printf("Dir de x: %p Valor: %d\n", (void*) x, *x);
    printf("Dir de y: %p Valor: %d\n", (void*) y, *y);
}