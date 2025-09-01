#include <stdio.h>

#define N 4


void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Como la operación % es el resto de hacer la división entera, tenemos que implementar la congruencia modulo entero t.q. el 0 <= r < |b|:
int mod(int a, int b) {
    return (a % b + b) % b;
}

int main() {
    int r = 6;
    int arr[N] = {1, 2, 3, 4};
    int res[N];

    printf("Arreglo original:\n");
    print_array(arr, N);
    for (int i = 0; i < N; i++) {
        res[mod(i-r, N)] = arr[i];
    }
    printf("Arreglo modificado:\n");
    print_array(res, N);

    return 0;
}