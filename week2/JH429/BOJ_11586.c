#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int N, K;
    char princess[MAX_SIZE][MAX_SIZE + 1];

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%s", princess[i]);
    }   

    scanf("%d", &K);

    switch(K) {
        case 1:
            for(int i = 0; i < N; i++) 
                printf("%s\n", princess[i]);
            break;
        case 2:
            for(int i = 0; i < N; i++) {
                for(int j = N - 1; j >= 0; j--)
                    printf("%c", princess[i][j]);
                printf("\n");
            }

            break;
        case 3:
            for(int i = N - 1; i >= 0; i--)
                printf("%s\n", princess[i]);
            break;
    }

    return 0;
}