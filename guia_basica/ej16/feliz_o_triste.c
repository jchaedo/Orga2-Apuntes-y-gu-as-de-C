#include <stdio.h>
#define FELIZ 0
#define TRISTE 1



void ser_feliz(int estado);
void print_estado(int estado);

int main(){
    int estado = TRISTE; // automatic duration. Block scope
    ser_feliz(estado);
    print_estado(estado); // qué imprime?: TRISTE. Porque la función que llamamos no cambia el valor de estado.
}

void ser_feliz(int estado){     // como los parámetros se pasan por copia, esta función no cambia el estado de las variables
    estado = FELIZ;
}

void print_estado(int estado){
    printf("Estoy %s\n", estado == FELIZ ? "feliz" : "triste");
}