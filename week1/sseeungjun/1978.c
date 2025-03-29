#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d", &size);

    int* array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        int is_prime = 1; 

        if (array[i] <= 1) {
            is_prime = 0;
        }
        else {
            
            for (int j = 2; j < array[i]; j++) {
                if (array[i] % j == 0) {
                    is_prime = 0;  
                    break;
                }
            }
        }

        if (is_prime) {
            count++;
        }
    }

    printf("%d\n", count);

    free(array);
    return 0;
}