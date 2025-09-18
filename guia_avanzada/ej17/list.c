#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "list.h"
#include "type.h"

list_t* listNew(type_t t) {
    list_t* l = malloc(sizeof(list_t));
    l->type = t; // l->type es equivalente a (*l).type
    l->size = 0;
    l->first = NULL;
    l->last = NULL;
    
    return l;
}


void listAddFirst(list_t* l, void* data) {
    node_t* n = malloc(sizeof(node_t));
    switch(l->type) {
        case TypeFAT32:
            n->data = (void*) copy_fat32((fat32_t*) data);
            break;
        case TypeEXT4:
            n->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            n->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
        }
    
    if (l->size == 0) {
        l->last = n;
        n->next = NULL;
    } else {
        l->first->prev = n;
        n->next = l->first;        
    }
    
    l->first = n;
    n->prev = NULL;

    l->size++;
}

//se asume: i < l->size
void* listGet(list_t* l, uint8_t i){
    node_t* n = l->first;
    for(uint8_t j = 0; j < i; j++) {
    n = n->next;
    }

    return n->data;
}

//se asume: i < l->size
void* listRemove(list_t* l, uint8_t i){
    node_t* tmp = l->first;
    void* data = tmp->data;
    
    for (size_t j = 0; j < i; j++)
    {
        tmp = tmp->next;
        data = tmp->data;
    }

    // ahora estamos en el nodo i, y "data" tiene la data que corresp al nodo correcto
    
    if (l->size == 1) {
        l->first = NULL;
        l->last = NULL;
    } else {
        if (i == 0){
            l->first = tmp->next;
            l->first->prev = NULL;
        } else if (i == l->size -1) {
            l->last = tmp->prev;
            l->last->next = NULL;
        } else {
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
        }
    }
    free(tmp);
    l->size--;
    return data;
}

void listDelete(list_t* l){
    node_t* n = l->first;
    
    while(n){
        node_t* tmp = n;
        n = n->next;

        switch(l->type) {
            case TypeFAT32:
            rm_fat32((fat32_t*) tmp->data);
            break;
            case TypeEXT4:
            rm_ext4((ext4_t*) tmp->data);
            break;
            case TypeNTFS:
            rm_ntfs((ntfs_t*) tmp->data);
            break;
        }

        free(tmp);
    }


    free(l);
}

// asume que l->size != 0
node_t* getNodo(list_t* l, uint8_t i){
    node_t* n = l->first;
    
    for (size_t j = 0; j < i; j++)
    {
        n = n->next;
    }
    return n;
}

// asume que i y j son están en rango
void swapNodos(list_t *l, size_t i, size_t j) {

    // si son el mismo, no hacemos nada
    
    if ( i == j) return;

    node_t *n1 = getNodo(l, i);
    node_t *n2 = getNodo(l, j);
    
    node_t *n1_next = n1->next;
    node_t *n1_prev = n1->prev;
    
    node_t *n2_next = n2->next;
    node_t *n2_prev = n2->prev;

    // modificamos los nodos swappeados para que desde ellos vayamos a los que corresp

    if (n1_next == n2) {
        // ... n1 <--> n2 ...

        n2->next = n1;
        n1->prev = n2;
        
        n1->next = n2_next;
        n2->prev = n1_prev;

        // modificamos a los nodos vecinos para poder llegar al nodo swappeado desde ellos
        // (siempre asegurándonos de no dereferenciar a null)
        
        if (n2_next) n2_next->prev = n1;
        if (n1_prev) n1_prev->next = n2;


    } else if (n2_next == n1) {
        // ... n2 <--> n1 ...

        n2->prev = n1;
        n1->next = n2;
        
        n2->next = n1_next;
        n1->prev = n2_prev;

        // modificamos a los nodos vecinos para poder llegar al nodo swappeado desde ellos
        // (siempre asegurándonos de no dereferenciar a null)
        
        
        if (n1_next) n1_next->prev = n2;
        if (n2_prev) n2_prev->next = n1;


    } else {
        // no son adyacentes

        n1->next = n2_next;
        n1->prev = n2_prev;
        
        n2->next = n1_next;
        n2->prev = n1_prev;
    
        // modificamos a los nodos vecinos para poder llegar al nodo swappeado desde ellos
        // (siempre asegurándonos de no dereferenciar a null)
        
        // vecinos de n1
        if (n1_next) n1_next->prev = n2;
        if (n1_prev) n1_prev->next = n2;
    
        // vecinos de n2
        if (n2_next) n2_next->prev = n1;
        if (n2_prev) n2_prev->next = n1;
    }
    
    // asignamos los punteros al inicio o final según corresp.
    
    if (l->first == n1) l->first = n2;
    if (l->last == n1) l->last = n2;
    
    if (l->first == n2) l->first = n1;
    if (l->last == n2) l->last = n1;    
}