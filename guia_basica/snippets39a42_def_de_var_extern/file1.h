// file1.h
#ifndef FILE1_H
#define FILE1_H
#include <stdio.h>
#include "file1.h"

extern int count; // puedo hacer extern cuantas veces quiera, pero en algún momento debe ser definido o no va a compilar

void print_count();

#endif // FILE1_H