#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int end, int mid) {
    if (n == 1) {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n - 1, start, mid, end);
    printf("%d %d\n", start, end);
    hanoi(n - 1, mid, end, start);
}

int main() {
    int N;
    cin >> N;

    cout << (1LL << (long long)N) - 1 << endl; 

    if (N <= 20) {
        hanoi(N, 1, 3, 2, (1LL << N) - 1);
    } else {
        hanoi(N, 1, 3, 2, 20);
    }

    return 0;
}

