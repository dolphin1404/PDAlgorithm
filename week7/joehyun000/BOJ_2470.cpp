#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> search(vector<int>& v, int N) {
    int left = 0;
    int right = N - 1;
    long long min_diff = 2000000001; 
    int best_left = left, best_right = right;

    while (left < right) {
        int sum = v[left] + v[right];

        if (abs(sum) < min_diff) {
            min_diff = abs(sum);
            best_left = left;
            best_right = right;
        }

        if (sum > 0) {
            right -= 1;
        } else if (sum < 0) {
            left += 1;
        } else {
            break; 
        }
    }
    return {v[best_left], v[best_right]};
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> selected = search(v, N);
    
    if (selected[0] > selected[1]) {
        swap(selected[0], selected[1]);
    }
    
    cout << selected[0] << " " << selected[1] << endl;

    return 0;
}
