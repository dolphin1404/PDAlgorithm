#include <iostream>
#include <vector>
using namespace std;

void greedy(vector<int> arr) {
    long long maxProfit = 0;
    int maxPrice = 0;

    for(int i = arr.size()-1; i >= 0 ; i--) {
        if(maxPrice < arr[i]) {
            maxPrice = arr[i];
        }
        else {
            maxProfit += maxPrice - arr[i];
        }
    }
    cout << maxProfit;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for(int i =0; i<N; i++) {
            cin >> arr[i];
        }

        greedy(arr);
    }
}