// main.c
#include <stdio.h>
#include "file1.h"

void increment_count() {
    count++;
}

int main() {

    count = 10;
    print_count();
    increment_count();
    printf("Count en main: %d\n", count);
    
    return 0;
}