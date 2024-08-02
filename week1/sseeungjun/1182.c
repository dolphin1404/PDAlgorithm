#include<stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int array[100];
    int count = 0;
    int k = 2;
    if (a == 1) {
        return 0;
    }
    while (a > 1) {

        if (a % k == 0) {
            array[count] = k;

            if (a == k) {
                break;
            }
            a /= k;
            count++;

        }
        else {
            k++;
        }

    }

    for (int i = 0; i <= count; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}