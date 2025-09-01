#include <stdio.h>

int var1; // se inicializa automáticamente por ser global

int main() {
    int var2 = 1; // se declara e inicializa una variable local
    
    printf("var2 (block scope: main): %i\n", var2);
    printf("var1 (file scope): %i\n", var1);
    while (var2--) {
        int var1 = 2; // utilizamos el mismo identificador que el de la variable global para el de una local, por lo que ya no tenemos forma de acceder a la original
        printf("var1 (block scope: main:while): %i\n", var1);
    }
    printf("var1 (file scope): %i\n", var1); // recuperamos el acceso a la variable global, ya que salimos del scope del while

    return 0;
}