#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int x;
    int y;
} Pair;

int compare(const void* a, const void* b) {
    Pair* pairA = (Pair*)a;
    Pair* pairB = (Pair*)b;

    if (pairA->x == pairB->x) {
        return pairA->y - pairB->y;
    }
    else
        return pairA->x - pairB->x;
}

int main() {
    int n;
    scanf("%d", &n);
 
    Pair* array = (Pair*)malloc(n * sizeof(Pair));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &array[i].x, &array[i].y);
    }


    qsort(array, n, sizeof(Pair), compare);
 

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", array[i].x, array[i].y);
    }

    free(array);

    return 0;
}