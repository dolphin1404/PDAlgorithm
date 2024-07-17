#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
      while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
      }
      return a;
    }

int main() {
    int N,S;
    cin >> N >> S;
    int *arr = new int[N];

    for(int i=0; i< N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int result = abs(arr[0] - S);


    for (int i = 1; i < N; i++) {
        result = gcd(result, abs(arr[i] - S));
    }

    cout << result << endl;
    delete[] arr;
    return 0;
}