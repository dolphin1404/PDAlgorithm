#include <iostream>
#include <algorithm> 
using namespace std;

int greedy(int N, int M) {
    if (N == 1 || M == 1) return 1;

    if (N == 2) {
        return min(4, (M + 1) / 2);
    }
    if (M < 7) {
        return min(4, M);
    } 
    else {
        return M - 2;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int result = greedy(N, M);
    cout << result << endl; 

    return 0; 
}