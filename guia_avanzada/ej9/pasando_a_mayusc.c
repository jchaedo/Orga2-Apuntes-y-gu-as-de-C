#include <stdio.h>

int difConMayusc = 'a' - 'A';

int esMayuscula(char c){
    // los caracteres ASCII en mayúscula son las letras desde 'A' hasta 'Z',
    // que tienen asociados los valores desde 65 a 90 en el estándar ASCII.
    return (65 <= c && c<= 90);
}

void aMayusc(char* letra) {
    while (*letra != '\0') {
        if (esMayuscula(*letra)) {
            *letra = *letra + difConMayusc;
        }
        letra++;
    }
}

int main(void) {
    
    char str[] = "laLA123_-_-??";

    printf("El string original era: %s\n", str);
    aMayusc(str);
    printf("El string con minúsculas es: %s\n", str);

    
    return 0;
}