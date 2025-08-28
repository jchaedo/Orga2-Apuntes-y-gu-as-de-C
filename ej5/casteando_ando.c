#include <stdio.h>


int main() {

    printf("0.1 como float: %f \n", 0.1f);
    printf("0.1 como double: %f \n", 0.1); // no necesitamos aclarar porque el literal base de punto flotante es double

    printf("0.1 casteado de float a int: %d \n", (int) 0.1f);
    printf("0.1 casteado de double a int: %d \n", (int) 0.1);

    return 0;
}