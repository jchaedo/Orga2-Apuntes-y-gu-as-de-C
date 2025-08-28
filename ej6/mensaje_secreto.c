#include <stdio.h>


int main() {

    int mensaje_secreto[] = {116, 104, 101, 32, 103, 105, 102, 116, 32, 111, 102, 32, 119, 111, 114, 100, 115, 32, 105, 115, 32, 116, 104, 101, 32, 103, 105, 102, 116, 32, 111, 102, 32, 100, 101, 99, 101, 112, 116, 105, 111, 110, 32, 97, 110, 100, 32, 105, 108, 108, 117, 115, 105, 111, 110};
    
    // calculamos length con el tamaño de int que nuestra arquitectura tome
    // usamos size_t porque es el tipo que devuelve la operación sizeof, además de que es un tipo que se usa para tamaños de arreglos
    
    size_t length = sizeof(mensaje_secreto) / sizeof(int);

    char decoded[length];
    
    for (int i = 0; (size_t) i < length; i++) {
        decoded[i] = (char) (mensaje_secreto[i]); // casting de int a char
    }
    
    for (int i = 0; (size_t) i < length; i++) {
        printf("%c", decoded[i]);
    }
    printf("\n");

    return 0;
}