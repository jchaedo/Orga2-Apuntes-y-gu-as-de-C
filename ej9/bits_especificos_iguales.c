#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t num) {
    
    int cant_bits = sizeof(uint32_t) * 8;

    printf("En binario: ");

    for (int i = cant_bits; i > 0; i--) {
        if ((i % 4 == 0) && i != cant_bits) {
            printf(" ");
        }
        
        if ((num >> (i-1) ) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}


int main() {
    
    uint32_t a = 0xa0000001;
    uint32_t b = 0x10000007;
    
    uint32_t a_3bytes_mas_altos = a >> (32 - 3);
    uint32_t b_3bytes_menos_altos = 0x7 & b;

    printf("a = 0x%08x \n", a);
    print_binary(a);
    printf("b = 0x%08x \n", b);
    print_binary(b);
    printf("\n");
    
    printf("%08x \n", a_3bytes_mas_altos);
    print_binary(a_3bytes_mas_altos);
    printf("%08x \n", b_3bytes_menos_altos);
    print_binary(b_3bytes_menos_altos);
    printf("\n");
    
    printf("¿Los 3 bits más significativos de a son iguales a los 3 menos significativos de b?: %i \n", (a_3bytes_mas_altos == b_3bytes_menos_altos));

    return 0;
}