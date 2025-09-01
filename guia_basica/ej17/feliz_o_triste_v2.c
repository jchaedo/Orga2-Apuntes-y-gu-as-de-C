#include <stdio.h>
#define FELIZ 0
#define TRISTE 1

int estado = TRISTE; // static duration. File scope

void ser_feliz();
void print_estado();

int main(){
    print_estado(); // el valor inicial de la variable estado es TRISTE, por lo que va a imprimir "Estoy triste"
    ser_feliz();
    print_estado(); // qué imprime?: como cambiamos la variable estado con la función ser_feliz(que afecta a una variable global), ahora es FELIZ, por lo que va a imprimir "Estoy feliz"
}
void ser_feliz(){
    estado = FELIZ; // al ser una variable global, asignarle un valor adentro de su scope la cambia
}
void print_estado(){
    printf("Estoy %s\n", estado == FELIZ ? "feliz" : "triste");
}