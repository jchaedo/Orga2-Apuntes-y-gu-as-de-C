#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "type.h"


void printNodo(node_t *n) {
    printf("* Su dir es %p\n", (void*) n);
    printf("* data en %p\n", (void*) &n->data);
    printf("* next en %p\n", (void*) &n->next);
    printf("* prev en %p\n\n", (void*) &n->prev);
}

int main() {
    list_t* l = listNew(TypeFAT32);
    
    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
    
    listAddFirst(l, f1);
    listAddFirst(l, f2);

    size_t i = 0;
    size_t j = 1;

    printf("Lista en %p\n\n", (void*) l);


    printf("En pos %lu:\n", i);
    printNodo(getNodo(l, i));

    printf("En pos %lu:\n", j);
    printNodo(getNodo(l, j));

    printf("Usamos swapNodos en los nodos en las pos %lu y %lu \n\n", i, j);

    swapNodos(l, i, j);
    
    printf("Lista en %p\n\n", (void*) l);

    printf("En pos %lu:\n", i);
    printNodo(getNodo(l, i));

    printf("En pos %lu:\n", j);
    printNodo(getNodo(l, j));

    printf("Vamos a eliminar el nodo %lu:\n", j);
    
    listRemove(l, j);
    
    printf("Ahora el nodo %lu apunta a %p\n", j-1, (void *) (getNodo(l, j-1))->next);

    listDelete(l);

    // evitamos liberar la memoria asignada a f1 y f2, para provocar un memory leak y ver cómo lo muestra valgrind
    rm_fat32(f1);
    rm_fat32(f2);
    
    return 0;
}