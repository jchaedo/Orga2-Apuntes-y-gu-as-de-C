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
    void* data = NULL;
    node_t* tmp = NULL;
    
    if(i == 0){
        data = l->first->data;
        tmp = l->first;
        l->first = l->first->next;
        l->first->prev = NULL;
    } else if (i == l->size -1) {
        data = l->last->data;
        tmp = l->last;
        l->last = l->last->prev;
        l->last->next = NULL;
    } else{
        node_t* curr = l->first;
        
        while (i > 0) {
            // i == 1? y size = 2
            curr = curr->next;
            
            data = curr->data;
            tmp = curr;

            curr->prev->next = curr->next;

            curr->next->prev = curr->prev;

            i--;
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

void swapPointer(void * p1, void * p2) {
    void *temp = p1;

    p1 = p2;

    p2 = temp;
}

void swapNodos(list_t *l, size_t nodo1Index, size_t nodo2Index) {

    if ( l->size >= nodo1Index || l->size >= nodo2Index || nodo1Index == nodo2Index) {
        return;

    } else if ( nodo1Index == 0 || nodo1Index == 0) {
        
        node_t *primerNodo = l->first;
        node_t *nodoCasoNormalPrev = listGet(l, nodo1Index - 1);;
        
        if ( nodo1Index == 0) {
            
            nodoCasoNormalPrev = listGet(l, nodo2Index - 1);
        
        } 

        // Swappeamos las struct que apuntan a c/ nodo

        swapPointer(l->first, nodoCasoNormalPrev->next);

        node_t *nodo1 = primerNodo->next;
        node_t *nodo2 = nodoCasoNormalPrev->next;

        // Swappeamos el nodo que le sigue al c/u

        swapPointer(nodo1->next, nodo2->next);

    } else {
        
        node_t *nodo1Prev = listGet(l, nodo1Index - 1);
        node_t *nodo2Prev = listGet(l, nodo2Index - 1);
        
        node_t *nodo1 = nodo1Prev->next;
        node_t *nodo2 = nodo2Prev->next;
    
        // Definimos los prev
        
        swapPointer(nodo1Prev->next, nodo2Prev->next);
    
        // Definimos los post
    
        swapPointer(nodo1->next, nodo2->next);

    }   
}