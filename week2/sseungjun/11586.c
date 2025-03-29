#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int** array = (int**)malloc(n * sizeof(int*));

    for(int i=0;i<n;i++){
        array[i] = (int*)malloc(n*sizeof(int));
    }
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c", &array[i][j]);
        }
    }
    int ch;
    switch (ch)
    {
    case 1:
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c", array[i][j]);
            }
        }
        break;
    case 2:
        for(int i =0; i<n; i++){
            for(int j=n-1;j=0;j--){
                printf("%c", array[i][j]);
            }
        }
        break;
    case 3:
        for(int i = n -1;i=0;i--){
            for(int j=n-1;j=0;j--){
                printf("%c", array[i][j]);
            }
        }
        break;

    default:
        break;
    }
}