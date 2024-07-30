#include <stdio.h>
#include<stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int size;
    int d;
    scanf("%d %d", &size, &d);

    int* array = malloc(size * sizeof(int));
    int* result = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    int k = abs(array[0] - d);
    for (int j = 1; j < size; j++) {
        k = gcd(k, abs(array[j] - d));
    }

    for (int i = 0; i < size; i++) {
        int is_prime = 1;

        if (array[i] <= 1) {
            is_prime = 0;
        }

    }

    printf("%d\n", k);

    free(array);
    return 0;
}