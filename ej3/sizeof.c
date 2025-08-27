#include <stdio.h>

int main() {

    char ci = 100; // tratamos al char como un entero
    short s = 100;
    int i = 100;
    long l = 100;
    long long ll = 100;
    float f = 100;
    double d = 100;
    long double ld = 100;
    char cc = 100; // tratamos al char como char
    int* i_ptr = &i;
    char* c_ptr = &ci;
    void* v_ptr = &ci; // al ser void pointer puede direccionar a elem de cualquier tipo
    
    // --
    printf("Imprimimos valores enteros:\n\n");
    
    printf("char(%lu): %d \n", sizeof(ci), ci);
    printf("short(%lu): %d \n", sizeof(s), s);
    printf("int(%lu): %d \n", sizeof(i), i);
    printf("long(%lu): %ld \n", sizeof(l), l);
    printf("long long(%lu): %lld \n", sizeof(ll), ll);
    printf("\n");
    
    printf("Imprimimos valores reales:\n\n");
    
    printf("float(%lu): %f \n", sizeof(f), f);
    printf("double(%lu): %f \n", sizeof(d), d);
    printf("long double(%lu): %Lf \n", sizeof(ld), ld);
    printf("\n");

    printf("Imprimimos valores de tipo caracter:\n\n");
    
    printf("char(%lu): %c \n", sizeof(cc), cc);
    printf("\n");
    
    printf("Imprimimos valores de tipo puntero:\n\n");
    
    /* Tenemos que castear a (void*) a los ptr a otros tipos para poder printear la dirección.
    Es la única forma en la que C nos deja */
    printf("int*(%lu): %p \n", sizeof(i_ptr), (void *) i_ptr);
    printf("char*(%lu): %p \n", sizeof(c_ptr), (void *) c_ptr);
    printf("void*(%lu): %p \n", sizeof(v_ptr), v_ptr);

    return 0;
}

