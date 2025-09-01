#include <stdio.h>

#define FELIZ 0
#define TRISTE 1

int estado = TRISTE; // static duration. File scope

void alcoholizar();
void print_estado();

int main(){
    print_estado(); //  comienza triste
    alcoholizar();  //  al tomar una vez, su estado pasa a ser feliz
    print_estado(); // feliz
    alcoholizar();alcoholizar();alcoholizar();  // como la variable es static, se mantiene el valor del contador en el scope de la función, pasa a estar triste
    print_estado(); // que imprime?: triste
}

void alcoholizar(){
    static int cantidad = 0; // static duration. block scope
    cantidad++;
    if(cantidad < 3){
        estado = FELIZ;
    }else{
        estado = TRISTE;
    }
}

void print_estado(){
    printf("Estoy %s\n", estado == FELIZ ? "feliz" : "triste");
}