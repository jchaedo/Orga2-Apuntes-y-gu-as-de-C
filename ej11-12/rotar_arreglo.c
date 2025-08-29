#include <stdio.h>

#define N 4


int main() {
    int r = 1;
    
    int arr[N] = {1, 2, 3, 4};
    int res[N];

    for (int i = 0; i < N; i++) {
        printf("%i ", arr[i]);
        res[(i-r) % N] = arr[i];
    }

    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%i ", res[i]);
    }
    printf("\n");

    return 0;
}