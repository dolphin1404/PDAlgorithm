#include <iostream>
using namespace std;

void search(int number, int digit, int arr[], int N, int S, int &count) {
    if (number == N) return;
    
    if (digit + arr[number] == S) count++;

    search(number + 1, digit, arr, N, S, count);
    search(number + 1, digit + arr[number], arr, N, S, count);
}

int main() {
    int N, S;
    int count = 0;

    cin >> N >> S;
    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    search(0, 0, arr, N, S, count);

    cout << count << endl;

    delete[] arr;  
    return 0;
}
