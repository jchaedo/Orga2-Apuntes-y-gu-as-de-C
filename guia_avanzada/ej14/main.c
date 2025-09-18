#include <stdio.h>
#include "list.h"
#include "type.h"


int main() {
    list_t* l = listNew(TypeFAT32);
    
    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
    
    listAddFirst(l, f1);
    listAddFirst(l, f2);

    printf("dir de mem de primer elem de la lista y su type: %p, %u\n\n", (void*)listGet(l, 0), l->type);

    listDelete(l);
    rm_fat32(f1);
    rm_fat32(f2);
    
    return 0;
}