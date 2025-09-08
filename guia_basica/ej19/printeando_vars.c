#include <stdio.h>

int g = 10; // var declarada y definida. file scope y duración estática

void functionA() {
    int a = 20;  // var declarada y definida. block scope y duración automática
    static int b = 30;   // var declarada y definida. block scope y duración estática
    
    printf("Dentro de functionA:\n");
    printf(" g = %d\n", g);
    printf(" a = %d\n", a);
    printf(" b = %d\n", b);
    
    // Modificación de las variables
    g += 5;
    a += 10;
    b += 5;
}

void functionB() {
    int a = 40;  // var declarada y definida. block scope y duración automática
    static int c = 50;  // var declarada y definida. block scope y duración estática
    
    printf("\nDentro de functionB:\n");
    printf(" g = %d\n", g);
    printf(" a = %d\n", a);
    printf(" c = %d\n", c);
    
    // Modificación de las variables
    g += 5;
    a += 10;
    c += 5;
}
int main() {
    printf("Dentro de main:\n");
    printf(" g = %d\n", g);
    // imprime 10

    functionA();
    // imprime 10, 20, 30
    functionB();
    // imprime 15, 40, 50
    functionA();
    // imprime 20, 20, 35
    functionB();
    // imprime 25, 40, 55
    
    printf("\nFinal en main:\n");
    printf(" g = %d\n", g);
    // imprime 30
    
    return 0;
}