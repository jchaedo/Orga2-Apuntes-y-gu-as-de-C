#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main(void) {

    printf("Vemos las funciones: strcpy, strcat, strlen, strcmp\n\n");

    char str[] = "Holalalala";

    printf("String: %s\n\n", str);
    
    size_t len = strlen(str);

    printf("Usando strlen, obtenemos: %lu (no cuenta el char '\\0')\n\n", len);

    char nuevo_str[len];

    printf("Copiamos dicho string con strcpy a la dirección de otro string: %s\n\n", str);

    strcpy(nuevo_str, str);

    printf("Ahora tenemos el mismo string en dos lugares: %p y %p\n\n", (void *)&str, (void *)&nuevo_str);

    char str_a_concat[len * 2 + 1];

    str_a_concat[0] = 'X';
    str_a_concat[1] = '\0';

    printf("Concatenamos el string %s y %s con strcat\n\n", str_a_concat, str);

    strcat(str_a_concat, str);
    
    printf("Obtenemos: %s en %p(la posición original de la primera parte concatenada)\n\n", str_a_concat, (void *)&str_a_concat);

    printf("Veamos si s1 = %s y s2 = %s son iguales con strcmp\n\n", str, str_a_concat);

    printf("La respuesta es: %i\n\n", strcmp(str, str_a_concat));

    printf("Si nuestra rta fue < 0 o > 0, entonces el n-ésimo elemento s1 era diferente al n-ésimo de s2. Y el código ASCII del elemento de s1 era menor o mayor respectivamente\n\n");

    printf("Si nuestra rta fue = 0, entonces str1 y str2 son iguales\n");


    return 0;
}
