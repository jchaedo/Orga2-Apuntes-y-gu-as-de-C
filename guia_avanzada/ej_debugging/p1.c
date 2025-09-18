#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
    char nombre[5];
    uint8_t habilitado; // bool
    int saldo;
    int gustoDeHeladoFavorito;
} usuario_t;


void habilitarUsuario(usuario_t *usuario){
    usuario->habilitado = 1;
    for(int i = 0; i <= 5; i++){            // el problema está acá. al acceder al "elemento 6" de nombre, en realidad nos estamos pasando del buffer nombre y pisando el siguiente byte, que corresp. a habilitado
        usuario->nombre[i] = '\0';
    }
    usuario->saldo = 0;
}
int main(void){
    usuario_t *nuevoUsuario = malloc(sizeof(usuario_t));
    habilitarUsuario(nuevoUsuario);
    
    if(nuevoUsuario->habilitado){
        printf("Usuario habilitado con éxito!\n");
    } else{
        printf("Error al habilitar usuario.\n");
    }
    
    free(nuevoUsuario);
    
    return 0;
}