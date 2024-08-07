#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int triangle[501][501] = {0}; 
    int arr[501][501] = {0}; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    arr[0][0] = triangle[0][0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                arr[i][j] = arr[i-1][j] + triangle[i][j];
            } else if (j == i) {
                arr[i][j] = arr[i-1][j-1] + triangle[i][j];
            } else {
                arr[i][j] = max(arr[i-1][j-1] + triangle[i][j], arr[i-1][j] + triangle[i][j]);
            }
        }
    }

    int maxSum = *max_element(arr[N-1], arr[N-1] + N);

    cout << maxSum << endl;
    return 0;
}
