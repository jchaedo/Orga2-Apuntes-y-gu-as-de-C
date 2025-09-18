#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s {
    // hay que definir struct nodo_s* acá porque el tipo nodo_t
    // no está declarado.
    struct nodo_s* siguiente;
    int valor;
} nodo_t;


typedef struct lista_s {
    nodo_t* cabeza;
} lista_t;

lista_t* crear_lista_vacia() {
    lista_t* lista_vacia = malloc(sizeof(lista_t));
    lista_vacia->cabeza = NULL; // El operador x->y es equivalente a (*x).y
    
    return lista_vacia;
}


nodo_t* crear_nuevo_nodo(int valor) {
    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->valor = valor;
    
    return nuevo_nodo;
}

void insertar_al_final(lista_t* lista, int valor) {
    nodo_t* actual = lista->cabeza;
    nodo_t* a_insertar = crear_nuevo_nodo(valor);
    
    
    // Caso lista vacia.
    // Intentar desreferenciar el puntero NULL causa un
    // Segmentation Fault (SIGSEGV).
    if (actual == NULL) {
        lista->cabeza = a_insertar;
        return;
    }
    
    while (actual->siguiente != NULL)
        actual = actual->siguiente;
    
    actual->siguiente = a_insertar;
}

int eliminar_cabeza(lista_t* lista) {
    nodo_t* actual = lista->cabeza;
    if (actual == NULL)
        return -1;
    
    lista->cabeza = actual->siguiente;
    
    free(actual);
    return 0;
}

void eliminar_lista(lista_t* lista) {
    nodo_t* actual = lista->cabeza;
    
    while (actual != NULL) {
        nodo_t* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    free(lista);
}

int size(lista_t *lista) {
    nodo_t *actual = lista->cabeza;

    int s = 0;
    while(!actual) {
        actual = actual->siguiente;
    }
    return s;
}

int eliminar_nodo(lista_t* lista, size_t i) {
    nodo_t *actual = lista->cabeza;
    
    if (actual == NULL || i >= size(l) || i < 0) return -1;
    
    if (size(l) == 1) {
        free(actual);
        lista->cabeza = NULL;
    } else if (i == 0) {
        lista->cabeza = actual->siguiente;
        free(actual);
    } else {        
        // caso gral.:
        
        nodo_t *prev = NULL;
        // vamos a pararnos en el nodo i
        for (int j = 0; j < i; j++) {
            prev = actual;
            actual = actual->siguiente;
        }
        
        // ahora que estamos parados en el nodo a borrar, y tenemos el anterior:
        
        prev->siguiente = actual->siguiente;
        free(actual);
    }
    
    return 0;
}

int mayor_a_uno(int){
    return res > 1;
}

void filter(lista_t* lista, int (*criterio)(int)){
    nodo_t *actual = lista->cabeza;

    // volvemos si la lista está vacía
    if (!actual) return;

    while(!actual) {
        if (!criterio(actual->valor)) {
            nodo_t *sig = actual->siguiente;
            eliminar_nodo(actual);
            actual = sig;
        }
    }
}

int main(void) {

    int valor = 1;

    lista_t *l = crear_lista_vacia();

    insertar_al_final(l, valor);
    insertar_al_final(l, valor);
    insertar_al_final(l, valor);

    filter(l, &mayor_a_uno);
    
    eliminar_lista(l);

    return 0;
}