#include <stdio.h>


int main() {
    int i = 1;
    int j = 1;

    printf("printeamos i: %i \n", i);
    printf("printeamos ++i: %i \n", ++i);
    printf("printeamos i: %i \n", i);
    
    printf("printeamos j: %i \n", j);
    printf("printeamos j++: %i \n", j++);
    printf("printeamos j: %i \n", j);

    return 0;
}