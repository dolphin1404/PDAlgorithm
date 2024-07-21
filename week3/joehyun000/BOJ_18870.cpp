#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> sorted_arr(arr);
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    for(int i = 0; i < N; ++i) {
        int index = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin();
        cout << index << ' ';
    }

    return 0;
}
