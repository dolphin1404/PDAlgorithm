#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[10000] = {0};
    int wine[10000] = {0};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> wine[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            arr[0] = wine[0];
        } else if (i == 1) {
            arr[1] = arr[0] + wine[1];
        } else if (i == 2) {
            arr[2] = max(wine[0] + wine[1], max(wine[0] + wine[2], wine[1] + wine[2]));
        } else {
            arr[i] = max(arr[i-1], max(arr[i-2] + wine[i], arr[i-3] + wine[i-1] + wine[i]));
        }
    }
    
    cout << arr[N-1] << endl;
    return 0;
}
