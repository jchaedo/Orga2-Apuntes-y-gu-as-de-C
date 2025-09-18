#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NAME_LEN 50
typedef struct persona_s {
    char nombre[NAME_LEN+1];
    int edad;
    struct persona_s* hijo;
} persona_t;


persona_t *crearPersona(char* nombre, int edad){
    persona_t *p = malloc(sizeof(persona_t));

    strcpy(p->nombre, nombre);
    p->edad = edad;
    p->hijo = NULL;

    return p;
}


void eliminarPersona(persona_t *p){
    
    free(p);
}

int main(void){
    
    char nombre[] = "carlos";
    
    unsigned int edad = 22;

    persona_t *p = crearPersona(nombre, edad);
    
    printf("Creamos una persona. Su nombre es %s y su edad es %i\n\n", p->nombre, p->edad);

    printf("La edad parámetro apunta a %p y la edad del struct apunta a %p\n\n", (void*) &edad, (void*) &(p->edad));

    printf("El nombre parámetro apunta a %p y el nombre del struct apunta a %p\n\n", (void*) &nombre, (void*) &(p->nombre));

    eliminarPersona(p);

    printf("Liberamos la memoria que contenía la información de la persona\n");

    return 0;
}