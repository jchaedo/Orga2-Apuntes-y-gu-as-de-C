#include <stdio.h>

int factorial(int n) {
    int res = 1;
    while (n > 0) {
        res *= n;
        n--;
    }
    
    return res;
}

int main(void) {
    int n = 0;
    printf("Inserte el número del que quiere calcular el factorial: ");
    scanf("%i", &n);
    printf("%i\n", factorial(n));

    return 0;
}