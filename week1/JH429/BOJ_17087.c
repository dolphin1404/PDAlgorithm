#include <stdio.h>

int GCD(int a, int b) {
    int c;
    while(b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int N, S, buf, gcd;
    int A[100000];

    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; i++){
        scanf("%d", &buf);
        A[i] = (buf >= S) ? (buf - S) : (S - buf);
    }
    
    /*if(N == 1){
        printf("%d", A[0]);
        return 0;
    }*/

    gcd = A[0];
    for(int i = 1; i < N; i++) 
        gcd = GCD(gcd, A[i]);

    printf("%d", gcd);

    return 0;
}