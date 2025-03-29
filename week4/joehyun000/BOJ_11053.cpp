#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> num(N);
    vector<int> arr(N,1);

    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for(int i =1; i< N; i++) {
        for(int j =0; j < i; j ++) {
            if(num[i] > num[j]) {
                arr[i] = max(arr[i], arr[j]+1);
            }
        }
    }
    cout << *max_element(arr.begin(), arr.end()) << endl;
}